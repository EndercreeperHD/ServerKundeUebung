#include "Kunde.h"

int  Kunde::autonr = 4710;

int Kunde::getKdNr()
{
	return kdNr;
}

Kunde::Kunde(string n)
{
		kdNr = ++autonr;
		name = n;	
}

Kunde::~Kunde(void)
{
}

void Kunde::eintragenVerbauch(int tag, int* werte)
{
}

