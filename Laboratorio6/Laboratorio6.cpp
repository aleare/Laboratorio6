// Laboratorio6.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
//Classi:
#include "Rectangle.h"
#include "Index.h"

using namespace std;

int main()
{
	//File Opening
	string nomefile;
	cout << "Inserire il nome del File da aprire:" << endl;
	cin >> nomefile;
	fstream file;
	file.open(nomefile);
	if (file.is_open() == false)
	{
		cout << "ERRORE NELL'APERTURA DEL FILE !" << endl;
		return 1;
	}
	cout << "File Aperto Correttamente !" << endl << endl;
	system("pause");
	//--------------------------------------------
	//File Reading
	int day = 0; int  month = 0; int year = 0; double amount = 0; int n = 0;
	string stringa; Index index;
	do
	{
		n++;
		file >> day;
		file.get();
		file >> month;
		file.get();
		file >> year;
		file >> stringa >> amount;
		file.get();
		char value = file.get();
		if (value == '-') amount = -amount;
		index.addTransaction(Transaction(Date(day, month, year), stringa, Amount(amount)));
	} while (!file.eof());
	index.removeTransaction(n - 1);
	//--------------------------------------------
	//Ui Drawing
	if (index.init() == true) { //Chiusura
		//File Saving
		//File Closing
		cout << "\n";
		file.close();
		return 0;
	}
	//File Closing
	cout << "\n";
	file.close();
	return 0;
}