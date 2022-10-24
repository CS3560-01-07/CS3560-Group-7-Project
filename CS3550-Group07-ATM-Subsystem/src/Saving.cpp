#include "../include/Saving.h"

Saving::Saving(const double& _IR, const double& _minDeposit)
{
	intrestRate = _IR;
	minDeposit = _minDeposit;
}


double Saving::getIntrestRate() const
{
	return intrestRate;
}
void Saving::setIntrestRate(double _IR)
{
	intrestRate = _IR;
}

double Saving::getMinDeposit() const
{
	return minDeposit;
}
void Saving::setMinDeposit(double _minDeposit)
{
	minDeposit = _minDeposit;
}