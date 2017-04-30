#pragma once
#include "Transaction.h"
#include "Date.h"
#include <vector>
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
	float monthlyExpenses(Date data);
	float yearlyExpenses(Date data);

	static bool valueCmp(Transaction  & a, Transaction  & b);

	//UI Opzions
	bool init() const;
	bool selection(int selection) const;

	// Output & Order Functions
	void print();
	void orderTransactions();
	void report();
	void yearSummary();
	~Index();
private:
	Menu menu;
	vector<Transaction> _transazione;
	int _ntransaction = 0;
};
