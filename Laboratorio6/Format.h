#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Rectangle.h"
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
};
