//This is a test comment
#include<iostream>
#include "Deposit.h"
#include "Account.h"
#include "ATMCard.h"
#include "Checking.h"
#include "Customer.h"
#include "Deposit.h"
#include "Saving.h"
#include "Transaction.h"
#include "Withdrawl.h"
using namespace std;

int main()
{

}
static String enterCardNo()
{
    /*
    prompt user for card number
    prompt user for pin number

    if (Object card Number !equals _cardNo || Object pin number !equal input pin number)
    {
        throw exception
    }
    
    fetch user account information 

    prompt user to choose account
   
    return account type name
    
    */
}

static void createTransfer()
{
    /*
    Ask user what account to transfer to

    Ask ammount to transfer

    Withdraw from first account

    Desposit ammount withrdawed from first account into second account.

    send digitial reciept to user's email

    */

}

// will seperate use cases later
static void createDepositOrWithdraw(int )
{
    /*Get 16 digit card number from user
	if (card exists in system)
	{
		
	
	//Get 4 digit pin number from user
		if (pin number is valid)
		{
			//Get user account type
			access the account type object (i.e either checking or saving)

			//Get Transaction Type
			create a new instance of the transaction type (i.e. either Deposit or Withdrawl)

				if (transaction is a deposit)
				{
					ask user how much they would like to deposit
					if (in saving mode)
					{
						
							if (deposit amount < minDeposit)
							{
								throw an errorand reprompt user to enter deposit amount
							}

					}
					update the user balance
					display new balance
                    send digitial reciept to user's email
					ask user if they would like to try again
				}
				else (transaction is a Withdrawl)
				{
					ask user how much they would like to Withdrawl
						if (in saving mode)
						{

							dipalay an error saying they can't Withdrawl in savings

						}
						else if (Withdrawl amount >= maxWithdrawl)
						{
							reprompt user to enter a valid Withdrawl amount
						}
						else
						{
                            if (Withdrawl amount > balance)
                            {    
                                overdraft protection function
							}
                            update the user balance
							display new balance
                            send digitial reciept to user's email
							ask user if they would like to try again
						}
				}
		}
		else
		{
			throw an exception
		}

	
	}
	else
	{
		throw an exception
	}
    */
}

static void overdraftProtection() 
{
    /*
        if(saving account balance >= checking account balance - withdrawl amount)
        {    
            transfer money from savings account to checking account
        }
        else
        {
            throw exception 
        }
    */
}