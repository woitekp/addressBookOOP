#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <fstream>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

class PlikZUzytkownikami
{
    const std::string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;// mozna od razu przypisac wartosc, ale wtedy ustawiona na sztywno. Zamiast tego skorzystamy z listy inicjalizacyjnej;

    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(std::string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(std::string NAZWAPLIKUZUZYTKOWNIKAMI) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(NAZWAPLIKUZUZYTKOWNIKAMI) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zmianaHaslaUzytkownikaWPliku( Uzytkownik uzytkownikDoEdycji );
};

#endif
