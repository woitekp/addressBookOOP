#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

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
    if (uzytkownicy.empty() == true)
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

void UzytkownikMenedzer::logowanieUzytkownika ( ) {
    std::string login = "";
    std::string haslo = "";
    std::cout << "Podaj login: ";
    std::cin >> login;
    for ( int i = 0, liczbaUzytkownikow = uzytkownicy.size(); i < liczbaUzytkownikow; i++ ) {
        std::cout << uzytkownicy[ i ].pobierzLogin() << std::endl;
        if ( uzytkownicy[ i ].pobierzLogin() == login ) {
            for ( int proby = 3; proby > 0; proby-- ) {
                std::cout << "\nPodaj haslo (pozostalo prob: " << proby << "): ";
                std::cin >> haslo;
                if ( uzytkownicy[ i ].pobierzHaslo() == haslo )
                {
                    std::cout << uzytkownicy[ i ].pobierzHaslo() << std::endl;
                    idZalogowanegoUzytkownika = uzytkownicy[ i ].pobierzId();
                    return;
                }
            }
            Sleep(5000);
            idZalogowanegoUzytkownika = 0;
            return;
        }
    }
    std::cout << "\nSuch user does not exists!";
    Sleep(2000);
    idZalogowanegoUzytkownika = 0;
    return;
}

/*void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    std::string login = "", haslo = "";

    std::cout << std::endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    std::vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr.pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                std::cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> haslo == haslo)
                {
                    std::cout << std::endl << "Zalogowales sie." << std::endl << std::endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr -> id;
                    return;
                }
            }
            std::cout << "Wprowadzono 3 razy bledne haslo." << std::endl;
            system("pause");
            idZalogowanegoUzytkownika = 0;
            return;
        }
        itr++;
    }
    std::cout << "Nie ma uzytkownika z takim loginem" << std::endl << std::endl;
    system("pause");
    idZalogowanegoUzytkownika = 0;
    return;
}*/

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i = 0, vectorSize = uzytkownicy.size(); i < vectorSize; i++)
    {
        std::cout << uzytkownicy[i].pobierzId() << std::endl;
        std::cout << uzytkownicy[i].pobierzLogin() << std::endl;
        std::cout << uzytkownicy[i].pobierzHaslo() << std::endl;
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    std::cout << "id zalogowanego uzytkownika: " << idZalogowanegoUzytkownika << std::endl;
    return idZalogowanegoUzytkownika;
}

