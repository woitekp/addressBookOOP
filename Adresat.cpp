#include "Adresat.h"

void Adresat::ustawId(int noweId)
{
    if ( noweId >= 0 )
        id = noweId;
}

void Adresat::ustawIdWlasciciela(int noweIdWlasciciela)
{
    idWlasciciela = noweIdWlasciciela;
}

void Adresat::ustawImie(std::string noweImie)
{
    imie = noweImie;
}

void Adresat::ustawNazwisko(std::string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Adresat::ustawNrTelefonu(std::string nowyNrTelefonu)
{
    nrTelefonu = nowyNrTelefonu;
}

void Adresat::ustawEmail(std::string nowyEmail)
{
    email = nowyEmail;
}

void Adresat::ustawAdres(std::string nowyAdres)
{
    adres = nowyAdres;
}


int Adresat::pobierzId()
{
    return id;
}

int Adresat::pobierzIdWlasciciela()
{
    return idWlasciciela;
}

std::string Adresat::pobierzImie()
{
    return imie;
}

std::string Adresat::pobierzNazwisko()
{
    return nazwisko;
}

std::string Adresat::pobierzNrTelefonu()
{
    return nrTelefonu;
}

std::string Adresat::pobierzEmail()
{
    return email;
}

std::string Adresat::pobierzAdres()
{
    return adres;
}

