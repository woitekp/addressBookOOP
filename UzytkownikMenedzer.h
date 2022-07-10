#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    std::vector <Uzytkownik> uzytkownicy;

    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    Uzytkownik podajDaneNowegoUzytkownika();
    void zmianaHaslaUzytkownikaWPliku( Uzytkownik uzytkownik );
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
};

#endif
