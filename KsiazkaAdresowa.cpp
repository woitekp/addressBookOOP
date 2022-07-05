#include "ksiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa()
{
    nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    dopiszUzytkownikaDoPliku(uzytkownik);

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

void KsiazkaAdresowa::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    std::fstream plikTekstowy;
    std::string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami, std::ios::app);
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << std::endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        std::cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << std::endl;
    plikTekstowy.close();
}

std::string KsiazkaAdresowa::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    std::string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += konwersjaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

std::string KsiazkaAdresowa::konwersjaIntNaString (int liczba)
{
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}

bool KsiazkaAdresowa::czyPlikJestPusty(std::fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, std::ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
