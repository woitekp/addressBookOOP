#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

class PlikTekstowy {

protected:
    const std::string NAZWA_PLIKU;

public:

    PlikTekstowy(std::string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}

    bool czyPlikJestPusty()
    {
        bool pusty = true;
        std::fstream plikTekstowy;
        plikTekstowy.open(NAZWA_PLIKU, std::ios::app);

        if (plikTekstowy.good() == true)
        {
            plikTekstowy.seekg(0, std::ios::end);
            if (plikTekstowy.tellg() != 0)
                {pusty = false;}
        }

        plikTekstowy.close();
        return pusty;
    }
};

#endif
