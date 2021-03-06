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
	static string saveFile();
	static void report();
	static void reportE();
	static void	transactionReport(string data, string description, string amount, bool positive);
	static void annualReport();
	static void transactionAnnual(string month, string positive, string negative, string balance);
	static void exit();
	//Debug
	static void debug();
	static void transactionDeleteList(string transaction, int number);
	~Menu();
};
