#include <iostream>
#include <vector>
#include <fstream>

#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU, std::ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        plikTekstowy << liniaZDanymiAdresata << std::endl;
        plikTekstowy.close();
        idOstatniegoAdresata++;
        return true;
    }
    else
    {
        std::cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU << " i zapisac w nim danych\n" << std::endl;
        return false;
    }
}

std::string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    std::string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdWlasciciela()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNrTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(std::string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    std::string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdWlasciciela(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNrTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;

            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

std::vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    std::vector<Adresat> adresaci;
    Adresat adresat;
    std::fstream plikTekstowy;
    std::string liniaZDanymiAdresata;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), std::ios::in);

    if(plikTekstowy.good())
    {
        while (getline(plikTekstowy, liniaZDanymiAdresata))
        {
            adresat = zaladujDaneAdresataZLinii(liniaZDanymiAdresata);
            if (adresat.pobierzIdWlasciciela() == idZalogowanegoUzytkownika)
                { adresaci.push_back(adresat);}
        }
        plikTekstowy.close();
        idOstatniegoAdresata = adresat.pobierzId();
    }
    else
    {
        plikTekstowy.close();
    }
    return adresaci;
}

Adresat PlikZAdresatami::zaladujDaneAdresataZLinii (std::string liniaZDanymi)
{
    Adresat adresatDoZaladowania;
    std::string poleZDanymi;
    size_t pozycjaSeparatora = liniaZDanymi.find( "|" );
    int i=0;
    while (pozycjaSeparatora != std::string::npos)
    {
        poleZDanymi = liniaZDanymi.substr(0, pozycjaSeparatora);
        switch ( i )
        {
            case 0: adresatDoZaladowania.ustawId(atoi( poleZDanymi.c_str())); break;
            case 1: adresatDoZaladowania.ustawIdWlasciciela(atoi( poleZDanymi.c_str() )); break;
            case 2: adresatDoZaladowania.ustawImie(poleZDanymi); break;
            case 3: adresatDoZaladowania.ustawNazwisko(poleZDanymi); break;
            case 4: adresatDoZaladowania.ustawNrTelefonu(poleZDanymi); break;
            case 5: adresatDoZaladowania.ustawEmail(poleZDanymi); break;
            case 6: adresatDoZaladowania.ustawAdres(poleZDanymi); break;
        }
        liniaZDanymi = liniaZDanymi.substr(pozycjaSeparatora+1, liniaZDanymi.length()-pozycjaSeparatora);
        pozycjaSeparatora = liniaZDanymi.find("|");
        i++;
    }
    return adresatDoZaladowania;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

bool PlikZAdresatami::edytujAdresataWPliku(Adresat adresat)
{
    int idAdresataDoEdycji = adresat.pobierzId();
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU, std::ios::in);
	if(!plikTekstowy.good())
    {
        std::cout << "BLAD! Nie mozna otworzyc pliku\n";
        system("pause");
        return false;
    }
    std::fstream tempFile;
    tempFile.open("temp", std::ios::out | std::ios::app);
	if(!tempFile.good())
    {
        std::cout << "BLAD! Nie mozna otworzyc pliku\n";
        system("pause");
        return false;
    }

    std::string linia;
    while (getline(plikTekstowy, linia))
    {
        size_t pozycjaSeparatora = linia.find("|");
        int ID = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        if ( ID != idAdresataDoEdycji )
        {
            tempFile << linia << std::endl;
        }
        else
        {
            tempFile << adresat.pobierzId() << "|"
                     << adresat.pobierzIdWlasciciela() << "|"
                     << adresat.pobierzImie() << "|"
                     << adresat.pobierzNazwisko() << "|"
                     << adresat.pobierzNrTelefonu() << "|"
                     << adresat.pobierzEmail() << "|"
                     << adresat.pobierzAdres() << "|\n";
        }
    }
    plikTekstowy.close();
    tempFile.close();
    const char* nazwaPlikuZAdresatami = NAZWA_PLIKU.c_str();
    std::remove(nazwaPlikuZAdresatami);
    std::rename("temp", nazwaPlikuZAdresatami);
    return true;
}

bool PlikZAdresatami::usunAdresataZPliku(int idAdresataDoUsuniecia)
{
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU, std::ios::in );
	if(!plikTekstowy.good())
    {
        std::cout << "BLAD! Nie mozna otworzyc pliku\n";
        system("pause");
        return false;
    }
    std::fstream tempFile;
    tempFile.open("temp", std::ios::out | std::ios::app);
	if(!tempFile.good())
    {
        std::cout << "BLAD! Nie mozna otworzyc pliku\n";
        system("pause");
        return false;
    }

    std::string linia;
    int idOstatniegoAdresata = 0;
    while (getline(plikTekstowy, linia))
    {
        size_t pozycjaSeparatora = linia.find("|");
        int ID = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        if (ID != idAdresataDoUsuniecia)
        {
            tempFile << linia << std::endl;
            idOstatniegoAdresata = ID;
        }
    }
    plikTekstowy.close();
    tempFile.close();
    const char* nazwaPlikuZAdresatami = NAZWA_PLIKU.c_str();
    std::remove(nazwaPlikuZAdresatami);
    std::rename("temp", nazwaPlikuZAdresatami);
    return true;
}

