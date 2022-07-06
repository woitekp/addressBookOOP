#include <sstream>
#include "MetodyPomocnicze.h"

std::string MetodyPomocnicze::konwersjaIntNaString (int liczba)
{
    std::ostringstream ss;
    ss << liczba;
    std::string str = ss.str();
    return str;
}
