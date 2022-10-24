#pragma once
#include "Account.h"
class Saving : public Account
{
public:
	//Constructor
	Saving(const double& _IR, const double& _minDeposit);

	//Getters and Setters for Intrest Rate
	double getIntrestRate() const;
	void setIntrestRate(double _IR);

	//Getters and Setters for Minimum Deposit
	double getMinDeposit() const;
	void setMinDeposit(double _minDeposit);
private:
	double intrestRate;
	double minDeposit;
};
