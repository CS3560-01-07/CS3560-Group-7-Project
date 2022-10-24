#pragma once
#include<iostream>
#include<string>
using namespace std;
class Customer
{
public:
	//Constructor
	Customer(const int &_custID, const int &_SSN, const int &_phoneNum, string &_email, string &_Name, string &_DOB, string &_address);

	//Getters and Setters for Customer ID
	int getCustomerID() const;
	void setCustomerID(int _custID);

	//Getters and Setters for Social Security Number
	int getSocialSecurityNum() const;
	void setSocialSecurityNum(int _SSN);

	//Getters and Setters for Phone Number
	int getPhoneNum() const;
	void getPhoneNum(int _phoneNum);

	//Getters and Setters for Email
	string getEmail() const;
	void getEmail(string _email);

	//Getters and Setters for Name
	string getName() const;
	void setName(string _Name);

	//Getters and Setters for Date of Birth
	string getDateOfBirth() const;
	void setDateOfBirth(string _DOB);

	//Getters and Setters for Address
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

