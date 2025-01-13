# ATM System

## Project Overview
![Problem Overview](screenshots/slide_1.png)
This project is an ATM system developed to emulate the functionalities of a traditional Automatic Teller Machine. It allows users to interact with their bank accounts for tasks such as deposits, withdrawals, transfers, and viewing transaction history.

The system was created for **Purloin Bank** to:
- Provide a cost-effective and efficient customer interaction channel.
- Enable account access outside regular branch hours.
- Reduce foot traffic in branches and decrease wait times.

## Features
![Purloin Bank Benefits](screenshots/slide_2.png)
- **Login System**: Authenticate users with a card number and PIN.
- **Account Management**: Switch between checking and savings accounts.
- **Transactions**: Perform deposits, withdrawals, and transfers.
- **Balance Inquiry**: View account balances.
- **Transaction History**: Review past transactions for both deposits and withdrawals.

## Technical Details
- **Programming Language**: C++ with Visual Studio CLR.
- **Database**: MySQL for account data storage and retrieval.
- **GUI**: Interactive user interface for emulating ATM operations.

### Database Schema
![Database Schema](screenshots/slide_6.png)
The database consists of tables for storing account details, transactions, and user authentication data. Key components include:
- Accounts table: User account information.
- Transactions table: Logs of deposits, withdrawals, and transfers.

## Setup Instructions
![Approach](screenshots/slide_3.png)
1. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   ```
2. **Set Up MySQL Database**:
   - Import the provided schema and data.
3. **Configure Database Connection**:
   - Update the `Constring` variable in the code with your database credentials.
4. **Build the Project**:
   - Open the solution in Visual Studio.
   - Build and run the project.

## Screenshots
Below are screenshots of the system's interface and functionality:

### Slides

1. **Problem Overview**
   ![Problem Overview](screenshots/slide_1.png)

2. **Purloin Bank Benefits**
   ![Purloin Bank Benefits](screenshots/slide_2.png)

3. **Approach**
   ![Approach](screenshots/slide_3.png)

4. **Domain Model Diagram**
   ![Domain Model Diagram](screenshots/slide_4.png)

5. **Use Case Diagrams**
   ![Use Case Diagrams](screenshots/slide_5.png)

6. **Database Schema**
   ![Database Schema](screenshots/slide_6.png)

7. **MySQL Tables**
   ![MySQL Tables](screenshots/slide_7.png)
   ![MySQL Tables](screenshots/slide_8.png)

9-13. **Database Connection Code: Making a Deposit**
   ![Database Connection Code](screenshots/slide_9.png)
   ![Database Connection Code](screenshots/slide_10.png)
   ![Database Connection Code](screenshots/slide_11.png)
   ![Database Connection Code](screenshots/slide_12.png)
   ![Database Connection Code](screenshots/slide_13.png)

14. **GUI Walkthrough**
   ![GUI Walkthrough](screenshots/slide_14.png)

15. **Login Page**
   ![Login Page](screenshots/slide_15.png)

16. **Account Selection**
    ![Account Selection](screenshots/slide_16.png)

17. **Main Menu**
    ![Main Menu](screenshots/slide_17.png)

18. **Transaction Pages**
    ![Transaction Pages](screenshots/slide_18.png)

19. **Check Balance Page**
    ![Check Balance Page](screenshots/slide_19.png)

20. **Transaction History Page**
    ![Transaction History Page](screenshots/slide_20.png)

21. **Difficulties Encountered**
    ![Difficulties Encountered](screenshots/slide_21.png)

22. **How We Resolved Our Difficulties**
    ![How We Resolved Our Difficulties](screenshots/slide_22.png)

23. **What We Learned**
    ![What We Learned](screenshots/slide_23.png)


## Authors
- Kevin Babakhani
- Emil Hovsepians
- Johnathan Driscoll
- Khaled Korfali
- Daniel Santamaria

