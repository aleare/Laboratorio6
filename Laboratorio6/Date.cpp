#include "stdafx.h"
#include "Date.h"

Date::Date(int day, int month, int year) : _iscorrect(true)
{
	_day = day;
	_month = month;
	_year = year;
}

Date::Date(int month, int year) : _iscorrect(true)
{
	_day = 01;
	_month = month;
	_year = year;
}

Date::Date(const Date& copy)
{
	_day = copy.getDay();
	_month = copy.getMonth();
	_year = copy.getYear();
	_iscorrect = copy.isCorrect();
}

void Date::operator=(const Date& equal)
{
	_day = equal.getDay();
	_month = equal.getMonth();
	_year = equal.getYear();
	_iscorrect = equal.isCorrect();
}

bool Date::operator>(const Date& data)
{
	if (_year > data.getYear())
	{
		return true;
	}
	else
	{
	}
}

int Date::getYear() const
{
	return _year;
}

int Date::getMonth() const
{
	return _month;
}

int Date::getDay() const
{
	return _day;
}

bool Date::isCorrect() const
{
	return true;
	//Da implementare!!!
}

void Date::setYear(int year)
{
	_year = year;
}

void Date::setMonth(int month)
{
	_month = month;
}

void Date::setDay(int day)
{
	_day = day;
}

std::string Date::str() const
{
	std::string stringa(std::to_string(_day));
	stringa.append("/");
	stringa.append(std::to_string(_month));
	stringa.append("/");
	stringa.append(std::to_string(_year));
	return stringa;
}

Date::~Date()
{
}