//
//  Deposit.cpp
//  CS3560 Skeleton Code
//
//  Created by Kevin Babakhani on 10/23/22.
//

#include <iostream>
#include <string>
#include "Deposit.h"

using namespace std;

Deposit::Deposit(double _theAmountDeposited)
{
    amountDeposited = _theAmountDeposited;
}

double Deposit::getAmountDeposited() const
{
    return amountDeposited;
}

void Deposit::setAmountDeposited(double _theAmountDeposited)
{
    amountDeposited = _theAmountDeposited;
}
