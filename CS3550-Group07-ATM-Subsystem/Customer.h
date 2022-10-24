#pragma once
#include<iostream>
#include<string>
using namespace std;
class Customer
{
public:
	int getCustomerID();
	int getSocialSecurityNum();
	int getPhoneNum();
	string getEmail();
	string getName();
	string getDateOfBirth();
	string getAddress();
private:
	int customerID;
	int socialSecurityNum;
	int phoneNum;
	string email;
	string name;
	string dateOfBirth;
	string address;
};

