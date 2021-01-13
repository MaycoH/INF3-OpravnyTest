#include "Student.h"

using namespace std;

Student::Student(char* pMeno, char* pPriezvisko, float pPriemer)
{
    meno = new char[strlen(pMeno) + 1];
    strcpy(meno, pMeno);

    priezvisko = new char[strlen(pPriezvisko) + 1];
    strcpy(priezvisko, pPriezvisko);

    priemer = pPriemer;
}

Student::Student(const Student& zdroj)
{
    if (this != &zdroj)
    {
        meno = new char[strlen(zdroj.meno) + 1];
        strcpy(meno, zdroj.meno);

        priezvisko = new char[strlen(zdroj.priezvisko) + 1];
        strcpy(priezvisko, zdroj.priezvisko);

        priemer = zdroj.priemer;
    }
}

Student& Student::operator=(const Student& zdroj)
{
    if (this != &zdroj)
    {
        // najskor musim vsetko zmazat
        Student::~Student();

        meno = new char[strlen(zdroj.meno) + 1];
        strcpy(meno, zdroj.meno);

        priezvisko = new char[strlen(zdroj.priezvisko) + 1];
        strcpy(priezvisko, zdroj.priezvisko);

        priemer = zdroj.priemer;
    }
    return *this;
}

Student::~Student()
{
    delete[] meno;
    delete[] priezvisko;
    priemer = 0.00;
}

void Student::Vypis()
{
    //cout << meno << " " << priezvisko << " " << priemer << endl;
    //cout << this->priezvisko << " " << this->meno << " " << fixed << setprecision(2) << this->getPriemer() << endl;     // #include <iomanip>
    printf("%.2f %s %s\n", priemer, priezvisko, meno);
}

float Student::getPriemer()
{
	return priemer;
}
