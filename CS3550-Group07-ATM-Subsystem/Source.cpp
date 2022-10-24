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
	//Get 16 digit card number from user
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
							dipalay an error saying they can't Withdrawl this amount
							reprompt user to enter a valid Withdrawl amount
						}
						else
						{
							update the user balance
								display new balance
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
	
}