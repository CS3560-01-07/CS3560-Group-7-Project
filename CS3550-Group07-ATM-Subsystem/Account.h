#pragma once
#include<iostream>
using namespace std;
class Account
{
    public:
        int getAccountNo();
        string getDateCreated();
        int getRoutingNo();
        int getBalace();
        int getMinBalance();

        void setAccountNo();
        void setDateCreated();
        void setRoutingNo();
        void setBalace();
        void setMinBalance();

    private:
        int accountNo;
        string dateCreated;
        int routingNo;
        int balance;
        int minBalance;
        
};

