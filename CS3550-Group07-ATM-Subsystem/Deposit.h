//
//  Deposit.h
//  CS3560 Skeleton Code
//
//  Created by Kevin Babakhani on 10/23/22.
//

#include "Transaction.h"
#include <string>
#ifndef Deposit_h
#define Deposit_h

using namespace std;

class Deposit : public Transaction
{
    private:
        double amountDeposited;


    public:
        Deposit(double = 0.0);
    
        double getAmountDeposited() const;
        void setAmountDeposited(double _theAmountDeposited);
};

#endif /* Deposit_h */
