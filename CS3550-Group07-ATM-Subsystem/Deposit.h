#pragma once
#include "Transaction.h"
class Deposit : public Transaction
{
public:
	void printName()
	{
		Transaction::getName();
		cout << "Deposit" << endl;
		cout << "Hello" << endl;
	}
};
