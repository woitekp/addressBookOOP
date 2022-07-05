#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"
#include <fstream>
#include <sstream>

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::string nazwaPlikuZUzytkownikami;

    std::vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    std::string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    std::string konwersjaIntNaString (int liczba);
    bool czyPlikJestPusty(std::fstream &plikTekstowy);

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


};
