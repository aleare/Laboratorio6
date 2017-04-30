#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
}

void Menu::printMain()
{	//Tabella di 72 caratteri
	std::cout
		<< " | " << Format::center("Programma di Ordinamento Entrate/Uscite", 10) << " | "
		<< Format::center("29/04/2017", 10) << " | "
		<< Format::center("David Costa", 10) << " | " << "\n"
		<< Format::innerline(MENUSIZE)
		<< Format::blanckline(MENUSIZE)
		<< Format::opz(1, "Aggiungi una transazione", MENUSIZE)
		<< Format::opz(2, "Rimuovi una transazione", MENUSIZE)
		<< Format::opz(3, "Esporta su un File", MENUSIZE)
		<< Format::opz(4, "Report", MENUSIZE)
		<< Format::opz(5, "Riassunto Annuale", MENUSIZE)
		<< Format::opz(6, "Uscita", MENUSIZE)
		<< Format::endline(MENUSIZE)
		<< "\n\n" << ">>";
}

void Menu::addTransaction()
{
}

void Menu::transactionAdded(string transaction)
{
	std::cout
		<< Format::textline("Transazione aggiunta correttamente!", MENUSIZE)
		<< Format::blanckline(MENUSIZE)
		<< Format::textline("La transazione e':", MENUSIZE)
		<< Format::textline(transaction, MENUSIZE)
		<< Format::blanckline(MENUSIZE)
		<< Format::textline("Salvare (S/N)", MENUSIZE)
		<< Format::endline(MENUSIZE)
		<< "\n\n";
}

void Menu::removeTransactionI()
{
	std::cout
		<< Format::textline("Ecco la lista di tutte le transazioni", MENUSIZE)
		<< Format::blanckline(MENUSIZE);
}

void Menu::removeTransactionE()
{
	std::cout
		<< Format::innerline(MENUSIZE)
		<< Format::textline("Si prega di selezionare il numero corrispondente:", MENUSIZE)
		<< Format::endline(MENUSIZE);
}

void Menu::exit()
{
	system("cls");
	std::cout
		<< Format::textline("Grazie per aver usato il programma...", MENUSIZE)
		<< Format::blanckline(MENUSIZE)
		<< Format::textline("Si desidera salvare le modifiche ? (S/N)", MENUSIZE)
		<< Format::endline(MENUSIZE)
		<< "\n\n" << ">>";
}

void Menu::debug()
{
	std::cout
		<< Format::textline("Prova di debug", MENUSIZE)
		<< Format::blanckline(MENUSIZE)
		<< Format::textline("Premere un tasto per tornare al menu", MENUSIZE)
		<< Format::endline(MENUSIZE)
		<< "\n\n" << ">>";
}

void Menu::listTransacion(string transaction, int number)
{
	std::cout
		<< Format::opz(number, transaction, MENUSIZE)
		<< Format::blanckline(MENUSIZE);
}

Menu::~Menu()
{
}