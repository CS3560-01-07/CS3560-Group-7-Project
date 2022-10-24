#pragma once
#include<iostream>
#ifndef ATMCard_h
#define ATMCard_h

using namespace std;
class ATMCard
{
    public:
        ATMCard(const int &_cardNo, string _expirDate, int 
        _securityCode, int _pinNo, int _currBal);
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
        int cardNo;
        string expirDate;
        int securityCode;
        int pinNo;
        int currBal;


};

#endif /* ATMCard_h */
