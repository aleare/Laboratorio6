#include "stdafx.h"
#include "Transaction.h"
#include <iostream>

Transaction::Transaction() : _data(01, 01, 2000), _amount(0)
{
	_description = "Nessuna Transazione";
	_missingdata = true;
}

Transaction::Transaction(Date data, std::string description, Amount amount) : _data(data), _amount(amount)
{
	_description = description;
	_missingdata = false;
}

Transaction::Transaction(Date data, Amount amount) : _data(data), _amount(amount)
{
	_description = "Nessuna Descrizione !";
	_missingdata = true;
}

Transaction::Transaction(const Transaction& copy) : _data(copy._data), _amount(copy._amount)
{
	_description = copy.getDescription();
}

void Transaction::operator=(const Transaction& equal)
{
	setData(equal._data);
	setAmount(equal._amount);
	setDescription(equal._description);
}

bool Transaction::operator==(const Transaction& equal) const
{
	if (_amount.operator==(equal._amount) && _data == equal._data&&_description == equal.getDescription())
	{
		return true;
	}
	else { return false; }
}

Date Transaction::getData()
{
	Date data(_data);
	return data;
}

std::string Transaction::getDescription() const
{
	return _description;
}

Amount Transaction::getAmount()
{
	Amount x(_amount);
	return x;
}

void Transaction::setData(Date data)
{
	_data.operator=(data);
}

void Transaction::setDescription(std::string description)
{
	_description = description;
}

void Transaction::setAmount(Amount amount)
{
	_amount.operator=(amount);
}

bool Transaction::dataMissing() const
{
	if (_missingdata == true)
	{
		return true;
	}
	else { return false; }
}

bool Transaction::isPositive() const
{
	return _amount.isPositive();
}

void Transaction::out() const
{
	std::cout << _data.str() << " " << _description << " " << _amount.str() << std::endl;
}

std::string Transaction::str() const
{
	std::stringstream ss;
	ss << _data.str() << " " << _description << " " << _amount.fStr();
	return ss.str();
}

Transaction::~Transaction()
{
}