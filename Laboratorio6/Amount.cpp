#include "stdafx.h"
#include "Amount.h"

Amount::Amount(double amount)
{
	_amount = amount;
}

Amount::Amount(const Amount& copy)
{
	_amount = copy.getAmount();
}

void Amount::operator=(const Amount& equal)
{
	_amount = equal.getAmount();
}

bool Amount::operator==(const Amount& cmp) const
{
	if (_amount == cmp._amount) {
		return true;
	}
	else { return false; }
}

double Amount::getAmount() const
{
	return _amount;
}

void Amount::setAmount(float amount)
{
	_amount = amount;
}

std::string Amount::str() const
{
	std::string stringa;
	if (_amount > 0)
	{
		stringa.append("+  ");
		stringa.append(std::to_string(_amount));
	}
	else if (_amount == 0)
	{
		stringa.append(std::to_string(_amount));
	}
	else
	{
		stringa.append("-  ");
		stringa.append(std::to_string(_amount));
	}
	return stringa;
}
std::string Amount::fStr() const
{
	std::string stringa;
	if (_amount > 0)
	{
		stringa.append(std::to_string(_amount));
		stringa.append(" +");
	}
	else if (_amount == 0)
	{
		stringa.append(std::to_string(_amount));
	}
	else
	{
		stringa.append(std::to_string(_amount));
		stringa.append(" -");
	}
	return stringa;
}

bool Amount::isPositive() const
{
	if (_amount >= 0)
	{
		return true;
	}
	else { return false; }
}

bool Amount::isNegative() const
{
	if (_amount <= 0)
	{
		return true;
	}
	else { return false; }
}

Amount::~Amount()
{
}