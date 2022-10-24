//
//  Withdrawl.h
//  CS3560 Skeleton Code
//
//  Created by Kevin Babakhani on 10/23/22.
//

#include "Transaction.h"
#include <string>
#ifndef Withdrawl_h
#define Withdrawl_h

using namespace std;

class Withdrawl : public Transaction
{
    private:
        double amountWithdrawn;


    public:
        Withdrawl(double = 0.0);
    
        double getAmountWithdrawn() const;
        void setAmountWithdrawn(double _theAmountWithdrawn);
};

#endif /* Withdrawl_h */
