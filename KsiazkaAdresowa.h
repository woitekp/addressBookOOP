#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    const std::string NAZWA_PLIKU_Z_ADRESATAMI;

    void menuUzytkownikow();
    void menuZAdresatami();
    void menuWyszukiwaniaAdresata();

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    bool czyUzytkownikJestZalogowany();

    void dodajAdresata();
    void wypiszWszystkichAdresatowUzytkownika();
    void szukajAdresata(std::string szukanaNazwa, std::string nazwaSzukanejDanej);
    void edytujAdresata();
    void usunAdresata();

public:
    KsiazkaAdresowa(std::string nazwaPlikuZUzytkownikami, std::string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenedzer = NULL; // analogicznie do std::string someString = "";
        menuUzytkownikow();
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
};

#endif
