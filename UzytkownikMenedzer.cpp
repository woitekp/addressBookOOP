#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    std::cout << std::endl << "Konto zalozono pomyslnie" << std::endl << std::endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
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

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if ( uzytkownicy.empty() )
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(std::string login)
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

void UzytkownikMenedzer::logowanieUzytkownika ( )
{
    std::string login = "";
    std::string haslo = "";
    std::cout << "Podaj login: ";
    std::cin >> login;
    for (int i = 0, liczbaUzytkownikow = uzytkownicy.size(); i < liczbaUzytkownikow; i++)
    {
        if (uzytkownicy[ i ].pobierzLogin() == login)
        {
            for (int proby = 3; proby > 0; proby--)
            {
                std::cout << "\nPodaj haslo (pozostalo prob: " << proby << "): ";
                std::cin >> haslo;
                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return;
                }
            }
            Sleep(5000); // block program
            idZalogowanegoUzytkownika = 0;
            return;
        }
    }
    std::cout << "\nNie istnieje uzytownik o podanym loginie\n";
    system("pause");
    idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogowanieUzytkownika ()
{
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenedzer::zmianaHaslaUzytkownika ()
{
    std::string haslo = "";
    std::cout << "Podaj nowe haslo: ";
    std::cin >> haslo;
    int indeksUzytkownikaDoEdycji = -1;
    for (int i = 0, liczbaUzytkownikow = uzytkownicy.size(); i < liczbaUzytkownikow; i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(haslo);
            indeksUzytkownikaDoEdycji = i;
            break;
        }
    }
    plikZUzytkownikami.zmianaHaslaUzytkownikaWPliku(uzytkownicy[indeksUzytkownikaDoEdycji]);
    std::cout << "\nZapisano zmiany\n";
    system("pause");
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i = 0, vectorSize = uzytkownicy.size(); i < vectorSize; i++)
    {
        std::cout << uzytkownicy[i].pobierzId() << std::endl;
        std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
        std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
    system("pause");
}
