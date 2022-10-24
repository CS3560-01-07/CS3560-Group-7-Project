//
//  Withdrawl.cpp
//  CS3560 Skeleton Code
//
//  Created by Kevin Babakhani on 10/23/22.
//

#include <iostream>
#include <string>
#include "../include/Withdrawl.h"

using namespace std;

Withdrawl::Withdrawl(double _theAmountWithdrawn)
{
    amountWithdrawn = _theAmountWithdrawn;
}

double Withdrawl::getAmountWithdrawn() const
{
    return amountWithdrawn;
}

void Withdrawl::setAmountWithdrawn(double _theAmountWithdrawn)
{
    amountWithdrawn = _theAmountWithdrawn;
}
