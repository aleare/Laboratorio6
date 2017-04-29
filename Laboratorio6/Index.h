#pragma once
#include "Transaction.h"
#include "Date.h"
#include "Rectangle.h"
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
	// Output & Order Functions
	void orderTransactions();
	void report();
	void yearSummary();
	~Index();
private:
	Transaction _transazione[N];
	int _ntransaction = 0;
};
