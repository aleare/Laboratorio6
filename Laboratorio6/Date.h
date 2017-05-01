#pragma once
#include <string>

class Date
{
public:
	Date(int day, int month, int year);
	Date(int month, int year);
	Date(const Date &copy);
	//Operators Overloads
	void operator=(const Date &equal);
	bool operator>(const Date &data) const;
	bool operator==(const Date &cmp) const;
	//Getters
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	bool isCorrect() const;
	//Setters
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	//OUT: A string containing "dd/mm/yyyy"
	std::string str() const;
	std::string strM() const;
	~Date();
private:
	int _year;
	int _month;
	int _day;
	bool _iscorrect;
};
