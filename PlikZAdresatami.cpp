#include <iostream>
#include <vector>
#include <fstream>

#include "PlikZAdresatami.h"


void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiAdresata = "";
    plikTekstowy.open(nazwaPlikuZAdresatami, std::ios::app);
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << std::endl << liniaZDanymiAdresata ;
        }
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac w nim danych." << std::endl;
    plikTekstowy.close();
}

bool PlikZAdresatami::czyPlikJestPusty(std::fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, std::ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
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
    std::fstream plikTekstowy;
    std::string linia;
    Adresat adresat;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), std::ios::in);

    if( plikTekstowy.good() ) {
        while ( getline( plikTekstowy, linia ) ) {
            adresat = zaladujDaneAdresataZLinii( linia );
            if ( adresat.pobierzIdWlasciciela() == idZalogowanegoUzytkownika )
                { adresaci.push_back( adresat ) ;}
        }
        plikTekstowy.close();
    }
    else {
        plikTekstowy.close();
    }
    return adresaci;
}

Adresat PlikZAdresatami::zaladujDaneAdresataZLinii ( std::string liniaZDanymi ) {
    Adresat adresatDoZaladowania;
    std::string pole;
    size_t pozycjaSeparatora = liniaZDanymi.find( "|" );
    int i=0;
    while ( pozycjaSeparatora != std::string::npos )
    {
        pole = liniaZDanymi.substr( 0, pozycjaSeparatora );
        switch ( i ) {
            case 0: adresatDoZaladowania.ustawId(atoi( pole.c_str())); break;
            case 1: adresatDoZaladowania.ustawIdWlasciciela(atoi( pole.c_str() )); break;
            case 2: adresatDoZaladowania.ustawImie(pole); break;
            case 3: adresatDoZaladowania.ustawNazwisko(pole); break;
            case 4: adresatDoZaladowania.ustawNrTelefonu(pole); break;
            case 5: adresatDoZaladowania.ustawEmail(pole); break;
            case 6: adresatDoZaladowania.ustawAdres(pole); break;
    }
        liniaZDanymi = liniaZDanymi.substr( pozycjaSeparatora+1, liniaZDanymi.length()-pozycjaSeparatora );
        pozycjaSeparatora = liniaZDanymi.find( "|" );
        i++;
    }
    return adresatDoZaladowania;
}
