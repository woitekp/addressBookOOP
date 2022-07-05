#include "Uzytkownik.h"

void Uzytkownik::ustawId(int noweId)
{
    if (noweId >= 0)
        id = noweId;
}
void Uzytkownik::ustawLogin(std::string nowyLogin)
{
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo(std::string noweHaslo)
{
    haslo = noweHaslo;
}

int Uzytkownik::pobierzId()
{
    return id;
}
std::string Uzytkownik::pobierzLogin()
{
    return login;
}
std::string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
