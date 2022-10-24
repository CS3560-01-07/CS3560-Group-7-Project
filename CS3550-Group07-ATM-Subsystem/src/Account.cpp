#include "../include/Account.h"

using namespace std;

//Constructer
Account::Account(const int  _accountNo, string _dateCreated, int 
    _routingNo, int _balance, int _minBalance) 
{
    accountNo = _accountNo;
    dateCreated = _dateCreated;
    routingNo = _routingNo;
    balance = _balance;
    minBalance = _minBalance;
}

// Getter Functions
int Account::getAccountNo()
{
    return accountNo;
}
string Account::getDateCreated()
{
    return dateCreated;
}
int Account::getRoutingNo()
{
    return routingNo;
}
int Account::getBalace()
{
    return balance;
}
int Account::getMinBalance()
{
    return minBalance;
}

//Setter Functions
void Account::setAccountNo(int _accountNo)
{
    accountNo = _accountNo;
}
void Account::setDateCreated(string _dateCreated)
{
    dateCreated = _dateCreated;
}
void Account::setRoutingNo(int _routingNo)
{
    routingNo = _routingNo;
}
void Account::setBalace(int _balance)
{
    balance = _balance;
}
void Account::setMinBalance(int _minBalance)
{
    minBalance = _minBalance;
}