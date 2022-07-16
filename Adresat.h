#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

class Adresat
{
    int id;
    int idWlasciciela;
    std::string imie;
    std::string nazwisko;
    std::string nrTelefonu;
    std::string email;
    std::string adres;

public:
    Adresat (int id=0, int idWlasciciela=0, std::string imie="", std::string nazwisko="", std::string nrTelefonu="", std::string email="", std::string adres="")
    {
        this->id = id;
        this->idWlasciciela = idWlasciciela;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->nrTelefonu = nrTelefonu;
        this->email = email;
        this->adres = adres;
    }
    void ustawId(int id);
    void ustawIdWlasciciela(int idWlasciciela);
    void ustawImie(std::string imie);
    void ustawNazwisko(std::string nazwisko);
    void ustawNrTelefonu(std::string nrTelefonu);
    void ustawEmail(std::string email);
    void ustawAdres(std::string adres);

    int pobierzId();
    int pobierzIdWlasciciela();
    std::string pobierzImie();
    std::string pobierzNazwisko();
    std::string pobierzNrTelefonu();
    std::string pobierzEmail();
    std::string pobierzAdres();
};

#endif
