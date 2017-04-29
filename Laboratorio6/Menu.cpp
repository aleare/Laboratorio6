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
		<< " | " << "1" << "   " << "Aggiungi una transazione" << "                                       |\n"
		<< " | " << "2" << "   " << "Rimuovi una transazione" << "                                        |\n"
		<< " | " << "3" << "   " << "Esporta su un File" << "                                             |\n"
		<< " | " << "4" << "   " << "Report" << "                                                         |\n"
		<< " | " << "5" << "   " << "Riassunto Annuale" << "                                              |\n"
		<< " | " << "6" << "   " << "Uscita" << "                                                         |\n"
		<< " ----------------------------------------------------------------------" << endl;
}

Menu::~Menu()
{
}