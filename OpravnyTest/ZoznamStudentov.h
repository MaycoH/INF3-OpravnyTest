#pragma once
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;

class ZoznamStudentov
{
private:
	Student** zoznamStudentov = nullptr;
	int pocetStudentov = 0;
	int pocetZapisanychStudentov = 0;
	ifstream input;

public:
	ZoznamStudentov(char* pNazovSuboru);
	void pridajStudenta(char* riadok);
	void pridajStudentaManualne(char* riadok);
	void vypisUsporiadanyZoznamStudentovPodlaPriemeru();
	~ZoznamStudentov();

private:
	void zoradStudentovPodlaPriemeru();
	void vymen(Student& studentA, Student& studentB);
};

