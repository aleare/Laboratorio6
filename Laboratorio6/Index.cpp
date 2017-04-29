#include "stdafx.h"
#include "Index.h"

Index::Index()
{
}

void Index::addTransaction(Transaction transaction)
{
	//Genera Errore
	_transazione[_ntransaction].operator=(transaction);
	_ntransaction++;
}

void Index::removeTransaction(Transaction transaction)
{
	//Da Implementare
}

void Index::removeTransaction(int ntransaction)
{
	delete &_transazione[ntransaction];
	//for (int i = ntransaction; i < N; ++i)
	//{
		//_transazione[i] = _transazione[i + 1];
	//}
}

float Index::monthlyExpenses(Date data)
{
	float tot = 0;
	for (int i = 0; i <= _ntransaction; ++i)
	{
		if (_transazione[i].getData().getMonth() == data.getMonth())
		{
			tot = tot + _transazione[i].getAmount().getAmount();
		}
	}
	return tot;
}

float Index::yearlyExpenses(Date data)
{
	float tot = 0;
	for (int i = 0; i <= _ntransaction; ++i)
	{
		if (_transazione[i].getData().getYear() == data.getYear())
		{
			tot = tot + _transazione[i].getAmount().getAmount();
		}
	}
	return tot;
}

void Index::orderTransactions()
{
	//Probabile ERRORE ! (Static)
	std::sort(_transazione.begin(), _transazione.end(), valueCmp);
}

void Index::report()
{
}

void Index::yearSummary()
{
}

bool Index::valueCmp(Transaction  &a, Transaction  &b)
{
	//Probabile ERRORE ! (Static)
	if (a.getData().operator>(b.getData()))
	{
		return false;
	}
	else { return true; }
}

void Index::print()
{
	for (int i = 0; i < _ntransaction; ++i)
	{
		_transazione[i].str();
	}
}

Index::~Index()
{
}