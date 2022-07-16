#include <iostream>
#include <vector>
#include <fstream>

#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, std::ios::app);

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
        std::cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI << " i zapisac w nim danych." << std::endl;
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
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), std::ios::in);

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

