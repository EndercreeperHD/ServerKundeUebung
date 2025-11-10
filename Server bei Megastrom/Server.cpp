#include "Server.h"

Server::Server(int port)
{
	serverSocket = new ServerSocket(port);
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


void Server::empfangeVomController()
{
	cout << "------------- Server Verbindung ------------- " << endl;
	cout << "Warte auf eine Clientanfrage mit accept() - blockierent!" << endl;
	
	// To Do

	cout << "Erfolgreiche Clientanfrage! Warte mit readLine() - blockierent!" << endl;
	
	// To Do
	string text = "";
	cout << "Empfangen von Controller: " << text << endl;

	// To Do

	
}

