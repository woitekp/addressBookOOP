#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI

#include <iostream>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
    const std::string NAZWA_PLIKU_Z_ADRESATAMI;// mozna od razu przypisac wartosc, ale wtedy ustawiona na sztywno. Zamiast tego skorzystamy z listy inicjalizacyjnej;
    int idOstatniegoAdresata;

    std::string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat zaladujDaneAdresataZLinii ( std::string liniaZDanymi );

public:
    PlikZAdresatami(std::string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    std::vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
};

#endif
