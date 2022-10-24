#pragma once
#include "Account.h"
class Checking : public Account
{
public:
	double getMaxWithdrawl() const;
	void setMaxWithrawl(double _maxWithdrawl);
private:
	double maxWithdrawl;
};

