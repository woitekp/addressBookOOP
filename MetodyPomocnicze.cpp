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
