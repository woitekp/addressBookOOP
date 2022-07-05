#include <iostream>
#include <vector>
#include <windows.h>
#include "Uzytkownik.h"


class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(std::string login);

public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


};
