#pragma once
#include<iostream>
#include<string>
using namespace std;
class Customer
{
public:
	int getCustomerID() const;
	void setCustomerID(int _custID);

	int getSocialSecurityNum() const;
	void setSocialSecurityNum(int _SSN);

	int getPhoneNum() const;
	void getPhoneNum(int _phoneNum);

	string getEmail() const;
	void getEmail(string _email);

	string getName() const;
	void setName(string _Name);

	string getDateOfBirth() const;
	void setDateOfBirth(string _DOB);

	string getAddress() const;
	void setAddress(string _address);
private:
	int customerID;
	int socialSecurityNum;
	int phoneNum;
	string email;
	string name;
	string dateOfBirth;
	string address;
};

