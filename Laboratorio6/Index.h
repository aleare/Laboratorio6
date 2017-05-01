#pragma once
#include "Transaction.h"
#include "Date.h"
#include <vector>
#include <fstream>
#include "Rectangle.h"
#include "Menu.h"
#include <algorithm>
#define N 50
class Index
{
public:
	Index();
	// Transaction Operations
	void addTransaction(Transaction transaction);
	void removeTransaction(Transaction transaction);
	void removeTransaction(int ntransaction);

	// Expenses Calculator
	double monthlyExpenses(Date data);
	double yearlyExpenses(Date data);

	//File Saving
	void fileSave(string nomefile);

	static bool valueCmp(Transaction  & a, Transaction  & b);

	//UI Opzions
	bool init();
	bool selection(int selection);

	//Cases
	void menuAddTransaction();
	void menuRemoveTransaction();

	// Output & Order Functions
	void print();
	void orderTransactions();
	void report();
	void yearSummary(int year);

	~Index();

private:
	Menu menu;
	vector<Transaction> _transazione;
	int ext = 0;
};
