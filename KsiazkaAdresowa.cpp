#include "ksiazkaAdresowa.h"

void KsiazkaAdresowa::menuUzytkownikow()
{
    char wyborUzytkownika;
    while (true)
    {
        system("cls");
        std::cout << "1. Zaloguj sie\n";
        std::cout << "2. Zarejestruj sie\n";
        std::cout << "3. Wyjscie\n";
        std::cin >> wyborUzytkownika;
        switch (wyborUzytkownika)
        {
            case '1':
                {
                    logowanieUzytkownika();
                    if (czyUzytkownikJestZalogowany())
                        {menuZAdresatami();}
                    break;
                }
            case '2': rejestracjaUzytkownika(); break;
            case '3': return;
        }
    }
}

void KsiazkaAdresowa::menuZAdresatami ()
{
    char wyborUzytkownika;
    while (true) {
        system("cls");
        std::cout << "1. Wyswietl kontakty\n";
        std::cout << "2. Szukaj\n";
        std::cout << "3. Dodaj kontakt\n";
        std::cout << "4. Edytuj kontakt\n";
        std::cout << "5. Usun kontakt\n";
        std::cout << "6. Zmien haslo\n";
        std::cout << "9. Wyloguj\n";
        std::cin >> wyborUzytkownika;
        switch (wyborUzytkownika)
        {
            case '1': wypiszWszystkichAdresatowUzytkownika(); break;
            case '2': menuWyszukiwaniaAdresata(); break;
            case '3': dodajAdresata(); break;
            case '4': edytujAdresata(); break;
            case '5': usunAdresata(); break;
            case '6': zmianaHaslaUzytkownika(); break;
            case '9': wylogowanieUzytkownika() ;return;
        }
    }
}

void KsiazkaAdresowa::menuWyszukiwaniaAdresata ()
{
    system("cls");
    std::cout << "1. Szukaj po imieniu\n";
    std::cout << "2. Szukaj po nazwisku\n";
    char wyborUzytkownika;
    std::cin >> wyborUzytkownika;
    std::string szukanaNazwa;
    switch ( wyborUzytkownika ) {
        case '1':
            std::cout << "Podaj imie: ";
            std::cin >> szukanaNazwa;
            szukajAdresata( szukanaNazwa, "imie" );
            break;

        case '2':
            std::cout << "Podaj nazwisko: ";
            std::cin >> szukanaNazwa;
            szukajAdresata( szukanaNazwa, "nazwisko" );
            break;
    }
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer->dodajAdresata(); // use arrow when operate on pointer
}

void KsiazkaAdresowa::wypiszWszystkichAdresatowUzytkownika()
{
    adresatMenedzer->wypiszWszystkichAdresatowUzytkownika();
}

void KsiazkaAdresowa::szukajAdresata(std::string szukanaNazwa, std::string nazwaSzukanejDanej)
{
    adresatMenedzer->szukajAdresata(szukanaNazwa, nazwaSzukanejDanej);
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}
