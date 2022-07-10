#include <iostream>

#include "ksiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"
//#include "Uzytkownik.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    //
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}
