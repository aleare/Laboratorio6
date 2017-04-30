#include "stdafx.h"
#include "Index.h"

Index::Index()
{
}

void Index::addTransaction(Transaction transaction)
{
	//_transazione[_ntransaction].operator=(transaction);
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
	for (int i = 0; i <= _transazione.size(); ++i)
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
	for (int i = 0; i <= _transazione.size(); ++i)
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

bool Index::init()
{
	system("cls");
	Menu::printMain();
	int select;
	cin >> select;
	if (selection(select) == true)
	{
		return true;
	}
	return false;
}

bool Index::selection(int selection)
{
	string sel(" ");
	switch (selection)
	{
	case(1)://Aggiungi Transazione
		menuAddTransaction();
		return false;
	case(2)://Rimuovi Transazione
		menuRemoveTransaction();
		return false;
	case(3)://Esporta su un file
		return false;
	case(4)://Report
		return false;
	case(5)://Riassunto Annuale
		return false;
	case(6)://Uscita
		Menu::exit();
		cin >> sel;
		//Implementare il salvataggio
		return true;
	default:
		int sselection = 0;
		std::cout
			<< "Selezione non corretta, riprovare...\n"
			<< ">> ";
		std::cin >> sselection;
		Index::selection(sselection);
		return false;
	}
}

void Index::menuAddTransaction()
{
	string description = "Nessuna descrizione"; string sign;
	string sel;
	double amount = 0;
	int day = 0, month = 0, year = 0; //for the addTransaction function
	Transaction transact(Date(20, 9, 1990), description, Amount(amount));
	Menu::addTransaction();
	cout << "Inserire il giorno:\n";
	cin >> day;
	cout << "Inserire il mese:\n";
	cin >> month;
	cout << "Inserire l'anno:\n";
	cin >> year;
	cout << "Inserire una descrizione di una parola:\n";
	cin >> description;
	cout << "Inserire la quantita' (virgola espressa con il punto):\n";
	cin >> amount;
	cout << "Inserire il segno [+/-]:\n";
	cin >> sign;
	transact.setData(Date(day, month, year));
	transact.setDescription(description);
	if (sign == "-") amount = -amount;
	transact.setAmount(Amount(amount));
	addTransaction(transact);
	system("cls");
	Menu::transactionAdded(transact.str());
	cin >> sel;
	if (sel == "S") init();
	else if (sel == "N")
	{
		system("cls");
		//rimuove l'ultima trasazione aggiunta
		removeTransaction(_transazione.size() - 1);
		init();
	}
	else {
		cout << "\nSelezione non valida..., La transazione non verr� salvata";
		removeTransaction(_transazione.size());
		system("pause");
		init();
	}
}

void Index::menuRemoveTransaction()
{
	int n;
	system("cls");
	Menu::removeTransactionI();
	for (int i = 0; i < _transazione.size(); ++i)
	{
		Menu::listTransacion(_transazione[i].str(), i);
	}
	Menu::removeTransactionE();
	cin >> n;
	string transactionremoved(_transazione[n].str());
	removeTransaction(n);
	cout << "La transazione :\n" << transactionremoved << "\n" << "E' stata rimosa correttamente\n\n";
	system("pause");
	init();
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