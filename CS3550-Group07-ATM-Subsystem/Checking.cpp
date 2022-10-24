#include "Checking.h"

Checking::Checking(const double& _maxWithdrawl)
{
	maxWithdrawl = _maxWithdrawl;
}

double Checking::getMaxWithdrawl() const
{
	return maxWithdrawl;
}
void Checking::setMaxWithrawl(double _maxWithdrawl)
{
	maxWithdrawl = _maxWithdrawl;
}