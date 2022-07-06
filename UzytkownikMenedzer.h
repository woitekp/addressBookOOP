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
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(std::string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
};

#endif
