#include "ATMCard.h"

using namespace std;

ATMCard::ATMCard(const int &_cardNo, string _expirDate, int 
    _securityCode, int _pinNo, int _currBal) 
{
    cardNo = _cardNo;
    expirDate = _expirDate;
    securityCode = _securityCode;
    pinNo = _pinNo;
    currBal = _currBal;
}

int ATMCard::getCarNo()
{
    return cardNo;
}
string ATMCard::getExpirDate()
{
    return expirDate;
}
int ATMCard::getSecrCode()
{
    return securityCode;
}
int ATMCard::getPinNo()
{
    return pinNo;
}
int ATMCard::getcurrBal()
{
    return currBal;
}

void ATMCard::setCarNo(int _cardNo)
{
    cardNo = _cardNo;
}
void ATMCard::setExpirDate(string _expirDate)
{
    expirDate = _expirDate
}
void ATMCard::setSecrCode(int _securityCode)
{
    securityCode = _securityCode;
}
void ATMCard::setPinNo(int _pinNo)
{
    pinNo = _pinNo
}
void ATMCard::setcurrBal(int _currBal)
{
    currBal = _currBal;
}
    