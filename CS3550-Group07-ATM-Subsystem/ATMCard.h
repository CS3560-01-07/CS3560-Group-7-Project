#pragma once
#include<iostream>
using namespace std;
class ATMCard
{
    public:
        int getCarNo();
        string getExpirDate();
        int getSecrCode();
        int getPinNo();
        int getcurrBal();

        void setCarNo(int _cardNo);
        void setExpirDate(string _expirDate);
        void setSecrCode(int _securityCode);
        void setPinNo(int _pinNo);
        void setcurrBal(int _currBal);
    

    private:
        const int cardNo;
        string expirDate;
        int securityCode;
        int pinNo;
        int currBal;


};

