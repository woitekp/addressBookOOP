#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "PlikZAdresatami.h"

class AdresatMenedzer
{
    std::vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    PlikZAdresatami plikZAdresatami;
    int pobierzIdNowegoAdresata();
    Adresat podajDaneNowegoAdresata();

public:
    AdresatMenedzer(std::string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    void dodajAdresata();
    void wypiszWszystkichAdresatowUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
};

#endif
