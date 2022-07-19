#include <sstream>
#include <iostream>
#include "MetodyPomocnicze.h"

std::string MetodyPomocnicze::konwersjaIntNaString (int liczba)
{
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}

std::string MetodyPomocnicze::wczytajLinie()
{
    std::string wejscie = "";
    getline(std::cin, wejscie);
    return wejscie;
}

int MetodyPomocnicze::wczytajLiczbe() {
    std::cin.clear();
    fflush(stdin);
    std::string input;
    int number = 0;

    while ( true ) {
        getline( std::cin, input );
        std::stringstream myStream( input );
        if ( myStream >> number ){ break;}
            std::cout << "To nie jest liczba. Podaj liczbe: ";
    }
    return number;
}

char MetodyPomocnicze::wczytajZnak() {
    std::cin.clear();
    fflush(stdin);
    std::string input = "";
    char character = '{0}';

    while ( true ) {
        getline( std::cin, input );
        if ( input.length() == 1 ) {
            character = input[0];
            break;
        }
        std::cout << "TO nie jest pojedynczy znak. Podaj znak: ";
    }
    return character;
}
