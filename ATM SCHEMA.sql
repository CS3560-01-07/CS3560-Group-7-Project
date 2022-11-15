DROP DATABASE ATM_SYSTEM;
CREATE DATABASE ATM_SYSTEM;
USE ATM_SYSTEM;

CREATE TABLE Customer (
	customerID int,
    socialSecurNo int,
    name VARCHAR(20),
    dateOfBirth datetime,
    address VARCHAR(50),
    phoneNum int,
    email VARCHAR(30),
    PRIMARY KEY (customerID)
);

CREATE TABLE AtmCard (
	cardNo int,
    expirDate datetime,
    pinNo int,
    currBalance decimal,
    PRIMARY KEY (cardNo)
);

CREATE TABLE Account (
	accountNo int,
    customerID int,
    dateCreated datetime,
    cardNo int,
    routingNumber int,
    balance decimal,
    minBalance decimal,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (customerID) REFERENCES Customer(customerID),
    FOREIGN KEY (cardNo) REFERENCES AtmCard(cardNo)
);

CREATE TABLE Saving (
	accountNo int,
    interestRate decimal,
    minDeposit  decimal,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Account(accountNo)
);

CREATE TABLE Checking (
	accountNo int,
    maxWithdrawAmt decimal,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Account(accountNo)
);


CREATE TABLE Transaction (
	transactionID int,
    accountNo int,
    dateOfTransaction datetime,
    timeOfTransaction time,
    PRIMARY KEY (transactionID),
    FOREIGN KEY (accountNo) REFERENCES Account(accountNo)
);

CREATE TABLE Withdraw (
	transactionID int,
    ammountWithdrawn decimal, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

CREATE TABLE Deposit (
	transactionID int,
    ammountDeposited decimal, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

