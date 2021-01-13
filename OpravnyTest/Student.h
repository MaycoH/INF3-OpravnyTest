#pragma once
#include <iostream>
#include <cstring>

class Student
{
private:
	char* meno = nullptr;
	char* priezvisko = nullptr;
	float priemer = 0.00;

public:
	Student(char* pMeno, char* pPriezvisko, float pPriemer);
	Student(const Student& zdroj);
	Student& operator=(const Student& zdroj);
	~Student();

	void Vypis();
	float getPriemer();		// pomocna metoda, ktoru vyuzivam pri sortovani
};

