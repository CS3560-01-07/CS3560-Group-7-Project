#pragma once
#include "Account.h"
class Saving : public Account
{
public:
	double getIntrestRate() const;
	void setIntrestRate(double _IR);

	double getMinDeposit() const;
	void setMinDeposit(double _minDeposit);
private:
	double intrestRate;
	double minDeposit;
};
