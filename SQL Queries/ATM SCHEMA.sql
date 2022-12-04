DROP DATABASE ATM_SYSTEM;

#Remove Comment "DROP DATABSE" after first run

CREATE DATABASE ATM_SYSTEM;
USE ATM_SYSTEM;
 
CREATE TABLE Customer (
	customerID int,
    socialSecurNo int,
    name VARCHAR(50),
    dateOfBirth VARCHAR(20),
    address VARCHAR(50),
    phoneNum bigint,
    email VARCHAR(100),
    PRIMARY KEY (customerID)
);

CREATE TABLE AtmCard (
	cardNo bigint,
    expirDate datetime,
    pinNo int,
    currBalance float,
    PRIMARY KEY (cardNo)
);

CREATE TABLE Accounts (
	accountNo int,
    customerID int,
    dateCreated datetime,
    cardNo bigint,
    routingNumber int,
    balance float,
    minBalance float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (customerID) REFERENCES Customer(customerID),
    FOREIGN KEY (cardNo) REFERENCES AtmCard(cardNo)
);

CREATE TABLE Saving (
	accountNo int,
    interestRate float,
    minDeposit  float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);

CREATE TABLE Checking (
	accountNo int,
    maxWithdrawAmt float,
    PRIMARY KEY (accountNo),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);


CREATE TABLE Transaction (
	transactionID int,
    accountNo int,
    dateOfTransaction datetime,
    timeOfTransaction time,
    PRIMARY KEY (transactionID),
    FOREIGN KEY (accountNo) REFERENCES Accounts(accountNo)
);

CREATE TABLE Withdraw (
	transactionID int,
    ammountWithdrawn float, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

CREATE TABLE Deposit (
	transactionID int,
    ammountDeposited float, 
    PRIMARY KEY (transactionID),
    FOREIGN KEY (transactionID) REFERENCES Transaction(transactionID)
);

