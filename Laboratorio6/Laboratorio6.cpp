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
	Index indice;
	indice.addTransaction(Transaction(Date(29, 9, 1997), "Prova", Amount(55)));
	indice.addTransaction(Transaction(Date(22, 3, 2000), "Prova2", Amount(88)));
	indice.addTransaction(Transaction(Date(22, 3, 2003), "Prova3", Amount(-88)));
	indice.addTransaction(Transaction(Date(22, 3, 2005), "Prova4", Amount(-88)));
	indice.print();
	indice.removeTransaction(2);
	indice.print();
	//--------------------------------------------
	//Ui Drawing
	//--------------------------------------------
	//File Closing
	file.close();
}