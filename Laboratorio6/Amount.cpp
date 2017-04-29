#include "stdafx.h"
#include "Amount.h"

Amount::Amount(float amount)
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

float Amount::getAmount() const
{
	return _amount;
}

void Amount::setAmount(float amount)
{
	_amount = amount;
}

std::string Amount::str()
{
	std::string stringa;
	if (_amount > 0)
	{
		stringa.append("+  ");
		stringa.append(std::to_string(_amount));
	}
	else if (_amount = 0)
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