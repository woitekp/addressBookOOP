#include "ksiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    std::string login;
    do
    {
        std::cout << "Podaj login: ";
        std::cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    std::string haslo;
    std::cout << "Podaj haslo: ";
    std::cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(std::string login)
{
    for (int i = 0, vectorSize = uzytkownicy.size(); i < vectorSize; i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            std::cout << std::endl << "Istnieje uzytkownik o takim loginie." << std::endl;
            return true;
        }
    }
    return false;
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    for (int i = 0, vectorSize = uzytkownicy.size(); i < vectorSize; i++)
    {
        std::cout << uzytkownicy[i].pobierzId() << std::endl;
        std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
        std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}
