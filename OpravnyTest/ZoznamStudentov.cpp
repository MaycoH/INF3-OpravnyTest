#include "ZoznamStudentov.h"

ZoznamStudentov::ZoznamStudentov(char* pNazovSuboru)
{
    // inicializacia velkosti zoznamu
	int pocetStudentov = 0;
	input.open(pNazovSuboru);
	if (input.is_open())
	{
		string riadok;
		while (getline(input, riadok))
			pocetStudentov++;
	}
	zoznamStudentov = new Student * [pocetStudentov];
	input.close();

    //nastavim kurzor opat na zaciatok suboru (nemusim zatvarat a znova otvarat subor)
    //input.clear();
    //input.seekg(0);

    // Parsovanie zoznamu studentov (pridavanie z .txt do zoznamu)
    input.open(pNazovSuboru);
    if (input.is_open())
    {
        //int index = 0;
        string riadok;

        while (getline(input, riadok))
        {
            pridajStudenta((char*)riadok.c_str());
        }
    }
    input.close();
}

void ZoznamStudentov::pridajStudenta(char* riadok)
{
    string slovo;
    stringstream ss(riadok);

    float priemer = 0.00;
    char* meno = nullptr;
    char* priezvisko = nullptr;

    int i = 0;

    while (!ss.eof())
    {
        ss >> slovo;
        switch (i) {
        case 0:
            priezvisko = new char[strlen(slovo.c_str()) + 1];
            strcpy(priezvisko, slovo.c_str());
            break;
        case 1:
            meno = new char[strlen(slovo.c_str()) + 1];
            strcpy(meno, slovo.c_str());
            
            break;
        case 2:
            priemer = stof(slovo);
            break;
        }
        i++;
        //ss >> priezvisko >> meno >> priemer;
    }
    zoznamStudentov[pocetZapisanychStudentov++] = new Student(meno, priezvisko, priemer);
    delete[] meno;
    delete[] priezvisko;
    //zoznamStudentov[pocetZapisanychStudentov - 1]->Vypis();         // Debug vypis

    // 2. sposob: nacitanie zo suboru a naplnenie zoznamu studentami (lok. prem.: string meno; string priezvisko; double priemer;)
    //string meno, priezvisko;
    //while (!input.eof())
    ////while (input >> priezvisko >> meno >> priemer)
    //{
    //    input >> priezvisko >> meno >> priemer;     // mozem pouzit aj ako podmienku v cykle (vid o 2 riadky vyssie)
    //    zoznamStudentov[pocetZapisanychStudentov++] = new Student((char*)meno.c_str(), (char*)priezvisko.c_str(), priemer);
    //}
}

void ZoznamStudentov::pridajStudentaManualne(char* riadok)
{
        			// Mozem inkrementovat az na konci a posunut ostatné indexy v metode
        Student** pomocnyZoznamStudentov = new Student*[pocetZapisanychStudentov + 1];
        //for (int i = 0; i < sizeof(zoznamNehnutelnosti); i++)
        // do noveho zoznamu nakopirujem stary (preto -1)
        for (int i = 0; i < pocetZapisanychStudentov; i++)
        {
            pomocnyZoznamStudentov[i] = this->zoznamStudentov[i];
        }

        // na posledne miseto vlozim novu nehnutelnost
        {
            string slovo;
            stringstream ss(riadok);

            float priemer = 0.00;
            char* meno = nullptr;
            char* priezvisko = nullptr;

            int i = 0;

            while (!ss.eof())
            {
                ss >> slovo;
                switch (i) {
                case 0:
                    priezvisko = new char[strlen(slovo.c_str()) + 1];
                    strcpy(priezvisko, slovo.c_str());
                    break;
                case 1:
                    meno = new char[strlen(slovo.c_str()) + 1];
                    strcpy(meno, slovo.c_str());

                    break;
                case 2:
                    priemer = stof(slovo);
                    break;
                }
                i++;
            }
            pomocnyZoznamStudentov[pocetZapisanychStudentov++] = new Student(meno, priezvisko, priemer);
            delete[] meno;
            delete[] priezvisko;
        }
        // vymazem povodny zoznam
        delete[] zoznamStudentov;
        // do zoznamu priradim pomocny zoznam
        zoznamStudentov = pomocnyZoznamStudentov;
        //delete[] pomocnyZoznamNehnutelnosti;
        //pocetZapisanychStudentov++;
}

void ZoznamStudentov::vypisUsporiadanyZoznamStudentovPodlaPriemeru()
{
    this->zoradStudentovPodlaPriemeru();

    for (int i = 0; i < pocetZapisanychStudentov; i++) {
        zoznamStudentov[i]->Vypis();
    }
}

ZoznamStudentov::~ZoznamStudentov()
{
    for (int i = 0; i < pocetZapisanychStudentov; i++)
    {
        delete zoznamStudentov[i];
    }
    delete[] zoznamStudentov;
    pocetStudentov = 0;
    pocetZapisanychStudentov = 0;
}

void ZoznamStudentov::zoradStudentovPodlaPriemeru()
{
    for (int i = 0; i < pocetZapisanychStudentov; i++)
    {
        for (int j = 0; j < pocetZapisanychStudentov - i - 1; j++)
        {
            if (zoznamStudentov[j]->getPriemer() > zoznamStudentov[j + 1]->getPriemer())
            {
                vymen(*zoznamStudentov[j], *zoznamStudentov[j + 1]);
            }
        }
    }
}

void ZoznamStudentov::vymen(Student& studentA, Student& studentB)
{
    Student tmp = studentA;
    studentA = studentB;
    studentB = tmp;
}
