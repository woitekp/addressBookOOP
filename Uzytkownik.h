#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

class Uzytkownik
{
    int id = 0;
    std::string login = "";
    std::string haslo = "";

public:
    void ustawId(int noweId);
    void ustawLogin(std::string nowyLogin);
    void ustawHaslo(std::string noweHaslo);

    int pobierzId();
    std::string pobierzLogin();
    std::string pobierzHaslo();
};

#endif
