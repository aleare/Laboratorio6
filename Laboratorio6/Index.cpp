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

double Index::monthlyExpenses(Date data)
{
	double tot = 0;
	for (int i = 0; i < _transazione.size(); ++i)
	{
		if (_transazione[i].getData().getYear() == data.getYear()) {
			if (_transazione[i].getData().getMonth() == data.getMonth())
			{
				tot = tot + _transazione[i].getAmount().getAmount();
			}
		}
	}
	return tot;
}

double Index::yearlyExpenses(Date data)
{
	double tot = 0;
	for (int i = 0; i < _transazione.size(); ++i)
	{
		if (_transazione[i].getData().getYear() == data.getYear())
		{
			tot = tot + _transazione[i].getAmount().getAmount();
		}
	}
	return tot;
}

void Index::fileSave(string nomefile)
{
	std::ofstream outfile(nomefile);
	for (int i = 0; i < _transazione.size(); ++i)
	{
		outfile << _transazione[i].str() << endl;
	}
	outfile.close();
}

void Index::orderTransactions()
{
	std::sort(_transazione.begin(), _transazione.end(), valueCmp);
}

void Index::report()
{
	Menu::report();
	orderTransactions();
	for (int i = 0; i < _transazione.size(); ++i)
	{
		Menu::transactionReport(_transazione[i].getData().str(), _transazione[i].getDescription(), std::to_string(_transazione[i].getAmount().getAmount()), _transazione[i].getAmount().isPositive());
	}
	Menu::reportE();
	system("pause");
	init();
}

void Index::yearSummary(int year)
{
	double tot = 0;
	double balance = 0;
	double plus = 0;
	double minus = 0;
	Menu::annualReport();
	for (int i = 1; i <= 12; ++i)
	{
		for (int k = 0; k < _transazione.size(); ++k)
		{
			if (_transazione[k].getData().getYear() == year) {
				if (_transazione[k].getData().getMonth() == i)
				{
					if (_transazione[k].isPositive() == true) {
						plus = plus + _transazione[k].getAmount().getAmount();
					}
					else
					{
						minus = minus + _transazione[k].getAmount().getAmount();
					}
				}
			}
		}
		balance = monthlyExpenses(Date(i, year));
		tot = tot + balance;
		Menu::transactionAnnual(Date(i, year).strM(), std::to_string(plus), std::to_string(minus), std::to_string(balance));
		balance = 0; plus = 0; minus = 0;
	}
	std::cout << "\n\nIl Totale dell'anno " << std::to_string(year) << " e':" << std::to_string(tot) << "\n\n";
	system("pause");
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

//UI Functions:
bool Index::init()
{
	if (ext == 1) //Exit param.
	{
		return true;
	}
	string sel;	//S save file N discard changes
	system("cls");
	Menu::printMain();
	int select;	//selection param.
	cin >> select;
	if (selection(select) == true)
	{
		cin >> sel;
		if (sel == "S") {
			ext = 1;	//Exit from init loop with true
		}
		else { ext = 0; }
	}
	return false;	//Exit from init loop with false
}

bool Index::selection(int selection)
{
	string sel(" ");
	int year;
	switch (selection)
	{
	case(1)://Aggiungi Transazione
		menuAddTransaction();
		return false;
	case(2)://Rimuovi Transazione
		menuRemoveTransaction();
		return false;
	case(3)://Esporta su un file
		system("cls");
		fileSave(Menu::saveFile());
		init();
		return false;
	case(4)://Report
		system("cls");
		report();
		return false;
	case(5)://Riassunto Annuale
		system("cls");
		std::cout << "Inserire l'anno:" << "\n" << ">>";
		std::cin >> year;
		system("cls");
		yearSummary(year);
		init();
		return false;
	case(6)://Uscita
		Menu::exit();
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
		cout << "\nSelezione non valida..., La transazione non verrà salvata";
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
		Menu::transactionDeleteList(_transazione[i].str(), i);
	}
	Menu::removeTransactionE();
	cin >> n;
	string transactionremoved(_transazione[n].str());
	removeTransaction(n);
	cout << "La transazione :\n" << transactionremoved << "\n" << "E' stata rimosa correttamente\n\n";
	system("pause");
	init();
}

//Debug Function:

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

///TODO LIST
//Fix S/N in menuAddTransaction