#pragma once

#include <limits.h>
#include <iostream>

#include "Customer_t.h"

class BankTeller_t {
private:
	unsigned long flCurrentBalance;
	int iCurrentTick;

public:
	BankTeller_t ( )
	{
		flCurrentBalance = LONG_MAX;
		iCurrentTick = 0;
	}

	int getCurrentTick ( )
	{
		return iCurrentTick;
	}

	void setCurrentTick ( const int newTick )
	{
		iCurrentTick = newTick;
	}

	void processCustomer ( Customer_t * customerRef )
	{
		if ( customerRef == nullptr || customerRef->getTransactionRef() == nullptr )
			return;

		Transaction_t *currentTransaction = customerRef->getTransactionRef ( );

		if ( currentTransaction->transactionType == TransactionType::DEPOSIT )
		{
			if ( flCurrentBalance >= LONG_MAX )
			{
				flCurrentBalance -= currentTransaction->flTransactionAmount;
			}

			std::cout << "[Teller] Processing your deposit " << customerRef->getFirstName ( ) << "!" << std::endl;

			flCurrentBalance += currentTransaction->flTransactionAmount;
			customerRef->setBalance ( customerRef->getCurrentBalance ( ) - currentTransaction->flTransactionAmount );

			std::cout << "[Teller] Successfully processed your deposit, thank you!" << std::endl;
		}
		else if ( currentTransaction->transactionType == TransactionType::WIDTHRAWAL )
		{
			if ( customerRef->getCurrentBalance ( ) < currentTransaction->flTransactionAmount )
			{
				std::cout << "[Teller] Well this is a little awkward, you don't have enough funds for the withdrawal! Couldn't process transaction." << std::endl;
				return;
			}
			
			std::cout << "[Teller] Processing your withdrawal " << customerRef->getFirstName ( ) << "!" << std::endl;

			flCurrentBalance -= currentTransaction->flTransactionAmount;
			customerRef->setBalance ( customerRef->getCurrentBalance ( ) + currentTransaction->flTransactionAmount );

			std::cout << "[Teller] Successfully processed your withdrawal, thank you!" << std::endl;
		}
	}
};