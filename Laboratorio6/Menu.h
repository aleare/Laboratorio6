#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Rectangle.h"
#include "Format.h"

#define MENUSIZE 72
class Menu
{
public:
	Menu();
	//Ui Drawing
	static void printMain();
	static void printTransactions();
	//Selections
	static void addTransaction();
	static void transactionAdded(string transaction);
	static void removeTransactionI();
	static void removeTransactionE();
	static void exit();
	//Debug
	static void debug();
	static void listTransacion(string transaction, int number);
	~Menu();
};
