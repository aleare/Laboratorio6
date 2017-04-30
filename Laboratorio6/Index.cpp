#include "stdafx.h"
#include "Index.h"

Index::Index()
{
}

void Index::addTransaction(Transaction transaction)
{
	//_transazione[_ntransaction].operator=(transaction);
	++_ntransaction;
	_transazione.push_back(transaction);
}

void Index::removeTransaction(Transaction transaction)
{
	for (int i = 0; i < _transazione.size(); ++i)
	{
		if (_transazione[i].operator==(transaction))
		{
			_transazione.erase(_transazione.begin() + i);
		}
	}
}

void Index::removeTransaction(int ntransaction)
{
	_transazione.erase(_transazione.begin() + ntransaction);
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

bool Index::init() const
{
	system("cls");
	menu.printMain();
	int select;
	cin >> select;
	if (selection(select) == true)
	{
		return true;
	}
	else { return false; }
}

bool Index::selection(int selection) const
{
	string sel;
	switch (selection)
	{
	case(1):
		menu.debug();
		cin >> sel;
		init();
		return false;
	case(2):
		return false;
	case(3):
		return false;
	case(4):
		return false;
	case(5):
		return false;
	case(6):
		menu.exit();
		cin >> sel;
		//Implementare il salvataggio
		return true;
	default:
		int sselection;
		std::cout
			<< "Selezione non corretta, riprovare...\n"
			<< ">> ";
		std::cin >> sselection;
		Index::selection(sselection);
		return false;
	}
}

void Index::print()
{
	for (int i = 0; i < _transazione.size(); ++i)
	{
		_transazione[i].str();
	}
}

Index::~Index()
{
}