//
//  Transaction.cpp
//  CS3560 Skeleton Code
//
//  Created by Kevin Babakhani on 10/23/22.
//

#include <iostream>
#include <string>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(const int &_theTransactionID, string _theDateOfTransaction, string _theTimeOfTransaction)
{
    transactionID = _theTransactionID;
    dateOfTransaction = _theDateOfTransaction;
    timeOfTransaction = _theTimeOfTransaction;
}

int Transaction::getTransactionID() const
{
    return transactionID;
}

void Transaction::setTransactionID(int _theTransactionID)
{
    transactionID = _theTransactionID;
}

string Transaction::getDateOfTransaction() const
{
    return dateOfTransaction;
}

void Transaction::setDateOfTransaction(string _theDateOfTransaction)
{
    dateOfTransaction = _theDateOfTransaction;
}

string Transaction::getTimeOfTransaction() const
{
    return timeOfTransaction;
}

void Transaction::setTimeOfTransaction(string _theTimeOfTransaction)
{
    timeOfTransaction = _theTimeOfTransaction;
}
