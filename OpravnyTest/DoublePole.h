#pragma once
class DoublePole
{
private:
    unsigned aPocet = 0;
    double** aData = nullptr;
public:
    DoublePole(unsigned pocet)
        : aPocet(pocet), aData(aPocet != 0 ? new double* [aPocet]:nullptr)
    {
        for (int i = 0; i < aPocet; i++)
        {
            aData[i] = new double(0.0);
        }
    }

    // Definovane v CPP subore:
    DoublePole(const DoublePole& zdroj);        // kopirovaci konstruktor
    DoublePole& operator=(const DoublePole& zdroj);     // operator priradenia
    ~DoublePole();          // destruktor
};
