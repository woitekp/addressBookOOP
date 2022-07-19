#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI

#include <iostream>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;

    std::string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat zaladujDaneAdresataZLinii ( std::string liniaZDanymi );

public:
    PlikZAdresatami(std::string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    std::vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    bool edytujAdresataWPliku(Adresat adresat);
    bool usunAdresataZPliku(int idAdresataDoUsuniecia);
};

#endif
