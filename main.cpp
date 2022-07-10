#include <iostream>

#include "ksiazkaAdresowa.h"
#include "UzytkownikMenedzer.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaUzytkownika();
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    //
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}
