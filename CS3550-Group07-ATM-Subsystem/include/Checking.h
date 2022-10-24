#pragma once
#include "Account.h"
class Checking : public Account
{
public:
	//Constructor
	Checking(const double& _maxWithdrawl);

	//Getters and Setters for Max WithdrawlAmmount
	double getMaxWithdrawl() const;
	void setMaxWithrawl(double _maxWithdrawl);
private:
	double maxWithdrawl;
};

