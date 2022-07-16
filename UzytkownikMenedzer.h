#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib> // pause
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    std::vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    bool czyIstniejeLogin(std::string login);
    int pobierzIdNowegoUzytkownika();
    Uzytkownik podajDaneNowegoUzytkownika();

public:
    UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
