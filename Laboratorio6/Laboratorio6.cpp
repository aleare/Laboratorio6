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
	cout << "File Aperto Correttamente !" << endl;
	system("pause");
	system("cls");
	//--------------------------------------------
	//File Reading
	int day = 0; int  month = 0; int year = 0; double amount = 0; int n = 0;
	string stringa; Index indice;
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
		indice.addTransaction(Transaction(Date(day, month, year), stringa, Amount(amount)));
		//cout << day << endl << year << endl << month << endl << stringa << endl << amount << endl;
	} while (!file.eof());
	indice.removeTransaction(n - 1);
	//--------------------------------------------
	//Ui Drawing

	//--------------------------------------------
	//File Closing
	file.close();
}