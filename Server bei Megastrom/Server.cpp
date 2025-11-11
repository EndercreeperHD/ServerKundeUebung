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
	while (1) {
		cout << "------------- Server Verbindung ------------- " << endl;
		cout << "Warte auf eine Clientanfrage mit accept() - blockierent!" << endl;

		Socket* work = serverSocket->accept();
		if (work == nullptr) continue;

		cout << "Erfolgreiche Clientanfrage! Warte mit readLine() - blockierent!" << endl;

		
		string text = work->readLine();
		cout << "Empfangen von Controller: " << text << endl;

		work->close();
		work = nullptr;
	}
}

