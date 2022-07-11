#include <iostream>
#include <vector>
#include <fstream>

#include "PlikZUzytkownikami.h"


void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami, std::ios::app);
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << std::endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << std::endl;
    plikTekstowy.close();
}

bool PlikZUzytkownikami::czyPlikJestPusty(std::fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, std::ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

std::string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    std::string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwersjaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    std::string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

std::vector<Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    std::fstream plikTekstowy;
    std::vector<Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;
    std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), std::ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }

    }
    plikTekstowy.close();
    return uzytkownicy;
}

void PlikZUzytkownikami::zmianaHaslaUzytkownikaWPliku( Uzytkownik uzytkownikDoEdycji )
{
    std::fstream plikTekstowy;
    plikTekstowy.open( nazwaPlikuZUzytkownikami , std::ios::in );
	if( !plikTekstowy.good() ) {
        std::cout << "Nie udalo sie zmienic hasla";
        return;
    }
    std::fstream tempFile;
    tempFile.open( "temp", std::ios::out | std::ios::app );
	if( !tempFile.good() ) {
        std::cout << "Nie udalo sie zmienic hasla";
        return;
    }

    std::string linia;
    int idUzytkownikaDoEdycji = uzytkownikDoEdycji.pobierzId();
    while ( getline( plikTekstowy, linia ) ) {
        std::cout << linia;
        size_t pozycjaSeparatora = linia.find( "|" );
        int ID = atoi( linia.substr( 0, pozycjaSeparatora ).c_str() );
        if ( ID != idUzytkownikaDoEdycji ) {
            tempFile << linia << std::endl;
        }
        else {
            tempFile << idUzytkownikaDoEdycji << "|"
                     << uzytkownikDoEdycji.pobierzLogin() << "|"
                     << uzytkownikDoEdycji.pobierzHaslo() << "|\n";
        }
    }
    plikTekstowy.close();
    tempFile.close();
    std::remove( nazwaPlikuZUzytkownikami.c_str() );
    std::rename( "temp", nazwaPlikuZUzytkownikami.c_str() );
    return;
}
