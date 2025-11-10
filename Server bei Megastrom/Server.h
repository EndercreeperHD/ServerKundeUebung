#pragma once
#include <list>
#include <iostream>
#include "ABI-Socket/ServerSocket.hpp"
#include "ABI-Socket/Socket.hpp"
#include "Kunde.h"

using namespace std;

// 2.5 Aufgabe
class Server
{
private:
	ServerSocket* serverSocket;
	Socket* arbeitsSocket;
	list<Kunde*> kunden;

public:
	Server(int port);
	~Server(void);

	Kunde* findeKunde(int kdNr);
	void empfangeVomController();

};

