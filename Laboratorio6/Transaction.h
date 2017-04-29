#pragma once
#include "Date.h"
#include "Amount.h"
class Transaction
{
public:
	//CTORS
	Transaction();
	Transaction(Date data, std::string description, Amount amount);
	Transaction(Date data, Amount amount);
	Transaction(const Transaction &copy);

	void operator=(const Transaction &equal);

	//Getters
	Date getData();
	std::string getDescription() const;
	Amount getAmount();

	//Setters
	void setData(Date data);
	void setDescription(std::string description);
	void setAmount(Amount amount);

	//Conditions
	bool dataMissing() const;
	bool isPositive() const;

	~Transaction();
private:
	Date _data;
	std::string _description;
	Amount _amount;
	bool _missingdata = true;
};
