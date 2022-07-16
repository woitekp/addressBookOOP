#include <iostream>
#include <vector>
#include <fstream>

#include "PlikZUzytkownikami.h"


void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI, std::ios::app);
    if (plikTekstowy.good())
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);
        plikTekstowy << liniaZDanymiUzytkownika << std::endl;
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_UZYTKOWNIKAMI << " i zapisac w nim danych." << std::endl;
    plikTekstowy.close();
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

    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), std::ios::in);

    if (plikTekstowy.good())
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

void PlikZUzytkownikami::zmianaHaslaUzytkownikaWPliku(Uzytkownik uzytkownikDoEdycji)
{
    std::fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI , std::ios::in);
	if(!plikTekstowy.good())
    {
        std::cout << "Nie udalo sie zmienic hasla";
        return;
    }
    std::fstream tempFile;
    tempFile.open("temp", std::ios::out | std::ios::app);
	if(!tempFile.good())
	{
        std::cout << "Nie udalo sie zmienic hasla";
        return;
    }

    std::string linia;
    int idUzytkownikaDoEdycji = uzytkownikDoEdycji.pobierzId();
    while (getline(plikTekstowy, linia))
    {
        size_t pozycjaSeparatora = linia.find( "|" );
        int ID = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        if (ID != idUzytkownikaDoEdycji)
        {
            tempFile << linia << std::endl;
        }
        else
        {
            tempFile << idUzytkownikaDoEdycji << "|"
                     << uzytkownikDoEdycji.pobierzLogin() << "|"
                     << uzytkownikDoEdycji.pobierzHaslo() << "|\n";
        }
    }
    plikTekstowy.close();
    tempFile.close();
    std::remove(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str());
    std::rename("temp", NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str());
}
