#include <iostream>
#include <vector>

#include "Uzytkownik.h"


class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    std::vector <Uzytkownik> uzytkownicy;

public:
    void rejestracjaUzytkownika();
};
