#include <iostream>
#include "Kunde.h"
#include "Server.h"

using namespace std;

int main()
{
	Kunde k1("Anton");
	Kunde k2("Betty");
	Server sv(54321);

	sv.empfangeVomController();


	system("pause"); 
	return 0;
}