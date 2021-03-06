#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Rectangle.h"
using namespace std;
class Format
{
public:

	Format()
	{
	}
	//Implement an opz(int n,string str,int b) who prints n <string> n_blank_spaces till <b>
	~Format()
	{
	}
	static std::string opz(int n, string str, int b)
	{
		string out(" | ");
		out.append(std::to_string(n));
		out.append("   ");
		out.append(str);
		const int m = b - out.size() - 1;
		for (int i = 1; i < m; ++i)
		{
			out.append(" ");
		}
		out.append("|\n");
		return out;
	}

	static std::string prd(const double x, const int decDigits, const int width) {
		stringstream ss;
		ss << fixed << right;
		ss.fill(' ');        // fill space around displayed #
		ss.width(width);     // set  width around displayed #
		ss.precision(decDigits); // set # places after decimal
		ss << x;
		return ss.str();
	}

	static std::string center(const string s, const int w) {
		stringstream ss, spaces;
		int padding = w - s.size();                 // count excess room to pad
		for (int i = 0; i < padding / 2; ++i)
			spaces << " ";
		ss << spaces.str() << s << spaces.str();    // format with padding
		if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
			ss << " ";
		return ss.str();
	}
	static std::string line(string character, int lenght)
	{
		string out;
		for (int i = 0; i < lenght; ++i)
		{
			out.append(character);
		}
		out.append("\n");
		return out;
	}
	static std::string line(int lenght) //Default "-" Char
	{
		string out;
		for (int i = 0; i < lenght; ++i)
		{
			out.append("-");
		}
		out.append("\n");
		return out;
	}
	static std::string endline(int lenght) //Default "-" Char
	{
		string out(" ");
		for (int i = 0; i < lenght - 2; ++i)
		{
			out.append("-");
		}
		out.append(" \n");
		return out;
	}
	static std::string blanckline(int lenght) //Default "-" Char
	{
		string out(" | ");
		for (int i = 0; i < lenght - 5; ++i)
		{
			out.append(" ");
		}
		out.append("|\n");
		return out;
	}
	static std::string innerline(int lenght) //Default "-" Char
	{
		string out(" |");
		for (int i = 0; i < lenght - 4; ++i)
		{
			out.append("-");
		}
		out.append("|\n");
		return out;
	}
	static std::string textline(string text, int lenght)
	{
		string out(" | ");
		out.append(text);
		const int m = lenght - out.size() - 1;
		for (int i = 1; i < m; ++i)
		{
			out.append(" ");
		}
		out.append("|\n");
		return out;
	}
	static std::string transaction(string data, string description, string amount, bool positive = true)
	{
		string out(" |  ");
		amount.resize(9);
		out.append(center(data, 18));
		out.append(" |  ");
		out.append(center(description, 18));
		if (positive == true)
		{
			out.append("|");
			out.append(center(amount, 12));
			out.append("|  ");
			out.append("          |\n");
		}
		else
		{
			out.append("|  ");
			out.append("          |");
			out.append(center(amount, 12));
			out.append("|\n");
		}
		return out;
	}
	static std::string transactionTitle(string data, string description, string amount, string negativeamount)
	{
		string out(" |  ");
		amount.resize(9);
		out.append(center(data, 18));
		out.append(" |  ");
		out.append(center(description, 18));
		out.append("|");
		out.append(center(amount, 12));
		out.append("|");
		out.append(center(negativeamount, 12));
		out.append("|\n");
		return out;
	}
	static std::string yearlySummaryTitle(string data, string amount, string negativeamount, string balance)
	{
		string out(" |");
		out.append(center(data, 16));
		out.append("|");
		out.append(center(amount, 16));
		out.append("|");
		out.append(center(negativeamount, 16));
		out.append("|");
		out.append(center(balance, 17));
		out.append("|\n");
		return out;
	}
	static std::string transactionYearly(string data, string positive, string negative, string balance)
	{
		string out(" |");
		positive.resize(9);
		negative.resize(9);
		balance.resize(9);
		out.append(center(data, 16));
		out.append("|");
		out.append(center(positive, 16));
		out.append("|");
		out.append(center(negative, 16));
		out.append("|");
		out.append(center(balance, 16));
		out.append(" |\n");
		return out;
	}
};
