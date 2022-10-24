#include "Customer.h"

int Customer:: getCustomerID() const
{
	return customerID;
}

void Customer::setCustomerID(int _custID)
{
	customerID = _custID;
}

int Customer::getSocialSecurityNum() const
{
	return socialSecurityNum;
}
void Customer::setSocialSecurityNum(int _SSN)
{
	socialSecurityNum = _SSN;
}

int Customer::getPhoneNum() const
{
	return phoneNum;
}
void Customer::getPhoneNum(int _phoneNum)
{
	phoneNum = _phoneNum;
}

string Customer::getEmail() const
{
	return email;
}
void Customer::getEmail(string _email)
{
	email = _email;
}

string Customer::getName() const
{
	return name;
}
void Customer::setName(string _Name)
{
	name = _Name;
}

string Customer::getDateOfBirth() const
{
	return dateOfBirth;
}
void Customer::setDateOfBirth(string _DOB)
{
	dateOfBirth = _DOB;
}

string Customer::getAddress() const
{
	return address;
}
void Customer::setAddress(string _address)
{
	address = _address;
}