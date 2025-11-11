#pragma once
#include <string>
using namespace std;

// 2.5 Aufgabe
class Kunde
{
private:
	static int autonr;
	int kdNr;
	string name;
	int verbrauchAktuellerMonat[31][24];
	int verbrauchVormonat[31] = {0};

public:
	Kunde(string n);
	~Kunde(void);

	void eintragenVerbauch(int tag,int* werte);
	int getKdNr();


};


