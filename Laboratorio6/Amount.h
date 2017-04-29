#pragma once
#include <string>

class Amount
{
public:
	Amount(double amount);
	Amount(const Amount &copy);
	void operator=(const Amount &equal);
	//Getter
	float getAmount() const;
	//Setter
	void setAmount(float amount);
	//OUT: A string containg "+/-   <amount>"
	std::string str() const;
	bool isPositive() const;
	bool isNegative() const;
	~Amount();
private:
	float _amount;
};
