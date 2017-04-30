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
};
