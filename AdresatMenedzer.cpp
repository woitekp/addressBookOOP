#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    std::string wynik = (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        ? "Nowy adresat zostal dodany\n" : "Blad - nie udalo sie dodac nowego adresata do pliku\n";
    std::cout << wynik << std::endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    system("cls");
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdWlasciciela(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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
    system("pause");
}

void AdresatMenedzer::szukajAdresata(std::string szukanaNazwa, std::string nazwaSzukanejDanej)
{
    int liczbaDopasowan = 0;
    if (nazwaSzukanejDanej == "imie")
    {
        for (int i = 0, liczbaAdresatow = adresaci.size(); i < liczbaAdresatow; i++)
        {
            if (adresaci[i].pobierzImie() == szukanaNazwa)
            {
                std::cout << "ID: " << adresaci[i].pobierzId() << std::endl;
                std::cout << "Imie: " << adresaci[i].pobierzImie() << std::endl;
                std::cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << std::endl;
                std::cout << "Nr telefonu: " << adresaci[i].pobierzNrTelefonu() << std::endl;
                std::cout << "Email: " << adresaci[i].pobierzEmail() << std::endl;
                std::cout << "Adres: " << adresaci[i].pobierzAdres() << std::endl;
                std::cout << std::endl;
                liczbaDopasowan++;
            }
        }
    }
    else if (nazwaSzukanejDanej == "nazwisko")
    {
        for (int i = 0, liczbaAdresatow = adresaci.size(); i < liczbaAdresatow; i++)
        {
            if (adresaci[i].pobierzNazwisko() == szukanaNazwa)
            {
                std::cout << "ID: " << adresaci[i].pobierzId() << std::endl;
                std::cout << "Imie: " << adresaci[i].pobierzImie() << std::endl;
                std::cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << std::endl;
                std::cout << "Nr telefonu: " << adresaci[i].pobierzNrTelefonu() << std::endl;
                std::cout << "Email: " << adresaci[i].pobierzEmail() << std::endl;
                std::cout << "Adres: " << adresaci[i].pobierzAdres() << std::endl;
                liczbaDopasowan++;
            }
        }
    }
    if ( liczbaDopasowan == 0 ) {
        std::cout << "Nie znaleziono kontaktow\n";
    }
    system("pause");
}

void AdresatMenedzer::edytujAdresata()
{
    system("cls");
    std::cout << "Podaj ID adresata do edycji: ";
    int idAdresataDoEdycji = MetodyPomocnicze::wczytajLiczbe();
    int indeksAdresataDoEdycji = -1;
    for (int i = 0, liczbaAdresatow = adresaci.size(); i < liczbaAdresatow; i++)
    {
        if (adresaci[i].pobierzId() == idAdresataDoEdycji)
        {
            indeksAdresataDoEdycji = i;
            break;
        }
    }
    if (indeksAdresataDoEdycji == -1)
    {
        std::cout << "Nie istnieje adresat o takim ID!\n";
        system("pause");
        return;
    }
    else
    {
        std::string nowaWartosc;
        std:: cout << "\nJaka dana chcesz edytowac?:\n1. Imie\n2. Nazwisko\n3. Nr telefonu\n4. Email\n5. Adres\n";
        int i = MetodyPomocnicze::wczytajLiczbe();
        switch ( i )
        {
            case 1:
                std::cout << "\nPodaj nowe imie: ";
                std::cin >> nowaWartosc;
                adresaci[indeksAdresataDoEdycji].ustawImie(nowaWartosc);
                break;
            case 2:
                std::cout << "\nPodaj nowe nazwisko: ";
                std::cin >> nowaWartosc;
                adresaci[indeksAdresataDoEdycji].ustawNazwisko(nowaWartosc);
                break;
            case 3:
                std::cout << "\nPodaj nowy nr telefonu: ";
                std::cin >> nowaWartosc;
                adresaci[indeksAdresataDoEdycji].ustawNrTelefonu(nowaWartosc);
                break;
            case 4:
                std::cout << "\nPodaj nowy email: ";
                std::cin >> nowaWartosc;
                adresaci[indeksAdresataDoEdycji].ustawEmail(nowaWartosc);
                break;
            case 5:
                std::cout << "\nPodaj nowy adres: ";
                std::cin >> nowaWartosc;
                adresaci[indeksAdresataDoEdycji].ustawAdres(nowaWartosc);
                break;
        }
    }

    std::string wynik = (plikZAdresatami.edytujAdresataWPliku(adresaci[indeksAdresataDoEdycji]))
        ? "Zapisano zmiany" : "Blad - nie udalo sie zapisac zmian";
    std::cout << wynik << std::endl;
    system("pause");
}

void AdresatMenedzer::usunAdresata()
{
    system("cls");
    std::cout << "Podaj ID adresata, ktorego chcesz usunac: ";
    int idAdresataDoUsuniecia = MetodyPomocnicze::wczytajLiczbe();
    for (int i = 0, liczbaAdresatow = adresaci.size(); i < liczbaAdresatow; i++)
    {
        if (adresaci[i].pobierzId() == idAdresataDoUsuniecia)
        {
            std::cout << "\nCzy na pewno usunac adresata? Jesli tak, nacisnij 't': ";
            char wyborUzytkownika = MetodyPomocnicze::wczytajZnak();
            if (wyborUzytkownika == 't')
            {
                adresaci.erase(adresaci.begin()+i);
                std::string wynik = (plikZAdresatami.usunAdresataZPliku(idAdresataDoUsuniecia))
                    ? "Usunieto adresata" : "Blad - nie udalo sie usunac adresata z pliku\n";
                std::cout << wynik << std::endl;
                system("pause");
                return;
            }
            else
            {
                system("pause");
                return;
            }
        }
    }
    std::cout << "Nie istnieje adresat o podanym ID\n";
    system("pause");
}
