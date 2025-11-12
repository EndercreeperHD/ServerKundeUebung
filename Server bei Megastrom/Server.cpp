#include "Server.h"

Server::Server(int port)
{
	serverSocket = new ServerSocket(port);
	arbeitsSocket = nullptr;
}

Server::~Server(void)
{
	delete serverSocket;
	delete arbeitsSocket;
}

Kunde* Server::findeKunde(int kdNr)
{
	for (Kunde* k : kunden) {
		if (k->getKdNr() == kdNr) return k;
	}
	return nullptr;
}
void Server::addKunden(Kunde* k) {
	kunden.push_back(k);
}


void Server::empfangeVomController()
{
	while (1) {
		cout << "------------- Server Verbindung ------------- " << endl;
		cout << "Warte auf eine Clientanfrage mit accept() - blockierent!" << endl;

		arbeitsSocket = serverSocket->accept();
		if (arbeitsSocket == nullptr) continue;

		cout << "Erfolgreiche Clientanfrage! Warte mit readLine() - blockierent!" << endl;

		
		string text = arbeitsSocket->readLine();
		cout << "Empfangen von Controller: " << text << endl;

		if (text.substr(0, 5) == "sende") cout << "sende erkannt\n";
		text.erase(0,6);
		string kdnr;
		for (int i = 0; text[i] != ' '; i++) {
			kdnr += text[i];
		}
		cout << kdnr << "\n";
		text.erase(0,kdnr.size()+1);
		string d;
		for (int i = 0; text[i] != ' '; i++) {
			d += text[i];
		}
		cout << d << "\n";
		text.erase(0, d.size()+1);

		int help = 0;
		int erg[24] = { 0 };
		for (int i = 0; i < 24; i++) {
			erg[i] = stoi(text.substr(help, text.find(';', help)));
			help = text.find(';', help) + 1;
		}
		cout << "Wandel den String in ein Feld von Integern um		"; for (int i : erg) cout << i << ' ';
		findeKunde(stoi(kdnr))->eintragenVerbauch(stoi(d),erg);
		cout << "\n";
		arbeitsSocket->close();
		delete arbeitsSocket;
		arbeitsSocket = nullptr;
	}
}

