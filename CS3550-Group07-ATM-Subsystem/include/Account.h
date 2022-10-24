#pragma once
#include<iostream>
#include<string>
#ifndef Account_h
#define Account_h

using namespace std;

class Account
{
    public:
        Account(const int  _accountNo, string _dateCreated, int 
    _routingNo, int _balance, int _minBalance); 

        int getAccountNo();
        string getDateCreated();
        int getRoutingNo();
        int getBalace();
        int getMinBalance();

        void setAccountNo(int _accountNo);
        void setDateCreated(string _dateCreated);
        void setRoutingNo(int _routingNo);
        void setBalace(int _balance);
        void setMinBalance(int _minBalance);

    private:
        int accountNo;
        string dateCreated;
        int routingNo;
        int balance;
        int minBalance;
        
};

#endif /* Account_h */