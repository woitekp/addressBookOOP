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
    for ( int i = 0, liczbaUzytkownikow = uzytkownicy.size(); i < liczbaUzytkownikow; i++ )
    {
        if ( uzytkownicy[ i ].pobierzLogin() == login )
        {
            for ( int proby = 3; proby > 0; proby-- )
            {
                std::cout << "\nPodaj haslo (pozostalo prob: " << proby << "): ";
                std::cin >> haslo;
                if ( uzytkownicy[ i ].pobierzHaslo() == haslo )
                {
                    idZalogowanegoUzytkownika = uzytkownicy[ i ].pobierzId();
                    return;
                }
            }
            Sleep(5000);
            idZalogowanegoUzytkownika = 0;
            return;
        }
    }
    std::cout << "\nNie istnieje uzytownik o podanym loginie";
    Sleep(2000);
    idZalogowanegoUzytkownika = 0;
    return;
}

void UzytkownikMenedzer::wylogowanieUzytkownika () {
    idZalogowanegoUzytkownika = 0;
    return;
}

void UzytkownikMenedzer::zmianaHaslaUzytkownika () {
    std::string haslo = "";
    std::cout << "Podaj nowe haslo: ";
    std::cin >> haslo;
    int indeksUzytkownikaDoEdycji = -1;
    for ( int i = 0, liczbaUzytkownikow = uzytkownicy.size(); i < liczbaUzytkownikow; i++ ) {
        if ( uzytkownicy[ i ].pobierzId() == idZalogowanegoUzytkownika ) {
            uzytkownicy[ i ].ustawHaslo( haslo );
            indeksUzytkownikaDoEdycji = i;
            break;
        }
    }
    zmianaHaslaUzytkownikaWPliku( uzytkownicy[ indeksUzytkownikaDoEdycji ]);
    std::cout << "\n\nZapisano zmiany";
    Sleep(2000);
    return;
}

void UzytkownikMenedzer::zmianaHaslaUzytkownikaWPliku( Uzytkownik uzytkownikDoEdycji ) {
    std::string nazwaPlikuZUzytkownikami = plikZUzytkownikami.pobierzNazwePlikuZUzytkownikami();
    std::fstream plik;
    plik.open( nazwaPlikuZUzytkownikami , std::ios::in );
	if( !plik.good() ) {
        std::cout << "Nie udalo sie zmienic hasla";
        Sleep(2000);
        return;
    }
    std::fstream tempFile;
    tempFile.open( "temp", std::ios::out | std::ios::app );
	if( !tempFile.good() ) {
        std::cout << "Nie udalo sie zmienic hasla";
        Sleep(2000);
        return;
    }

    std::string linia;
    int idUzytkownikaDoEdycji = uzytkownikDoEdycji.pobierzId();
    while ( getline( plik, linia ) ) {
        std::cout << linia;
        size_t pozycjaSeparatora = linia.find( "|" );
        int ID = atoi( linia.substr( 0, pozycjaSeparatora ).c_str() );
        if ( ID != idUzytkownikaDoEdycji ) {
            tempFile << linia << std::endl;
        }
        else {
            tempFile << idUzytkownikaDoEdycji << "|"
                     << uzytkownikDoEdycji.pobierzLogin() << "|"
                     << uzytkownikDoEdycji.pobierzHaslo() << "|\n";
        }
    }
    plik.close();
    tempFile.close();
    std::remove( nazwaPlikuZUzytkownikami.c_str() );
    std::rename( "temp", nazwaPlikuZUzytkownikami.c_str() );
    return;
}

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
    return idZalogowanegoUzytkownika;
}

