#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI

#include <iostream>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
    const std::string nazwaPlikuZAdresatami;// mozna od razu przypisac wartosc, ale wtedy ustawiona na sztywno. Zamiast tego skorzystamy z listy inicjalizacyjnej;

    bool czyPlikJestPusty(std::fstream &plikTekstowy);
    std::string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(std::string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat zaladujDaneAdresataZLinii ( std::string liniaZDanymi );

public:
    PlikZAdresatami(std::string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    void dopiszAdresataDoPliku(Adresat adresat);
    std::vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
};

#endif
