#include "AdresatMenedzer.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    std::cout << std::endl << "Adresat dodany pomyslnie" << std::endl << std::endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;

    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdWlasciciela(idZalogowanegoUzytkownika);

    std::string imie;
    std::cout << "Podaj imie: ";
    std::cin >> imie;
    adresat.ustawImie(imie);

    std::string nazwisko;
    std::cout << "Podaj nazwisko: ";
    std::cin >> nazwisko;
    adresat.ustawNazwisko(nazwisko);

    std::string nrTelefonu;
    std::cout << "Podaj numer telefonu: ";
    std::cin >> nrTelefonu;
    adresat.ustawNrTelefonu(nrTelefonu);

    std::string email;
    std::cout << "Podaj email: ";
    std::cin >> email;
    adresat.ustawEmail(email);

    std::string adres;
    std::cout << "Podaj adres: ";
    std::cin >> adres;
    adresat.ustawAdres(adres);

    return adresat;
}

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}

void AdresatMenedzer::wypiszWszystkichAdresatowUzytkownika()
{
    for (int i = 0, vectorSize = adresaci.size(); i < vectorSize; i++)
    {
        std::cout << adresaci[i].pobierzId() << std::endl;
        std::cout << adresaci[i].pobierzIdWlasciciela() << std::endl;
        std::cout << adresaci[i].pobierzImie() << std::endl;
        std::cout << adresaci[i].pobierzNazwisko() << std::endl;
        std::cout << adresaci[i].pobierzNrTelefonu() << std::endl;
        std::cout << adresaci[i].pobierzEmail() << std::endl;
        std::cout << adresaci[i].pobierzAdres() << std::endl;
    }
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika)
{
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}


