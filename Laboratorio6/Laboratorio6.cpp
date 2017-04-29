// Laboratorio6.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
//Classi:
#include "Rectangle.h"

using namespace std;

int main()
{
	//File Opening
	string nomefile;
	cout << "Inserire il nome del File da aprire:" << endl;
	cin >> nomefile;
	fstream file;
	file.open(nomefile);
	if (file.bad() == true)
	{
		cout << "ERRORE NELL'APERTURA DEL FILE !";
		return 1;
	}
	cout << "File Aperto Correttamente !";
	cout << "Premere INVIO per continuare...";
	system("cls");
	//--------------------------------------------

	file.close();
}