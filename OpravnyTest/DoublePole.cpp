#include "DoublePole.h"

DoublePole::DoublePole(const DoublePole& zdroj)
{
	if (&zdroj != this)
	{
		aPocet = zdroj.aPocet;
		aData = new double* [zdroj.aPocet];

		for (int i = 0; i < zdroj.aPocet; i++)
		{
			aData[i] = new double(*zdroj.aData[i]);
		}
	}
}

DoublePole& DoublePole::operator=(const DoublePole& zdroj)
{
	if (&zdroj != this)
	{
		for (int i = 0; i < zdroj.aPocet; i++)
		{
			delete aData[i];
		}
		delete[] aData;

		aPocet = zdroj.aPocet;
		aData = new double* [zdroj.aPocet];
		for (int i = 0; i < zdroj.aPocet; i++)
		{
			aData[i] = new double(*zdroj.aData[i]);
		}
	}
	return *this;
}

DoublePole::~DoublePole()
{
	for (int i = 0; i < aPocet; i++)
	{
		delete aData[i];
	}
	delete[] aData;
	aData = nullptr;
	aPocet = 0;
}
