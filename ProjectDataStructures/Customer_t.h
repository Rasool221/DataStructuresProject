#pragma once

#include <string>

#include "Transaction_t.h"

class Customer_t {
private:
	std::string strFirstName;
	std::string strMiddleName;
	std::string strLastName;

	double flCurrentBalance;
	Transaction_t *currentTransaction;
public:
	Customer_t ( )
	{
		strFirstName = strMiddleName = strLastName = "";

		flCurrentBalance = 0.f;
		currentTransaction = nullptr;
	}

	Customer_t ( std::string firstName, std::string middleName, std::string lastName, double currentBalance, Transaction_t* curTransaction)
	{
		strFirstName = firstName;
		strMiddleName = middleName;
		strLastName = lastName;

		flCurrentBalance = currentBalance;

		if ( curTransaction != nullptr )
		{
			*currentTransaction = *curTransaction;
		}
	}

	std::string getFirstName ( )
	{
		return strFirstName;
	}

	std::string getMiddleName ( )
	{
		return strMiddleName;
	}

	std::string getLastName ( )
	{
		return strLastName;
	}

	double getCurrentBalance ( )
	{
		return flCurrentBalance;
	}

	Transaction_t *getTransactionRef ( )
	{
		return currentTransaction;
	}

	void setFirstName ( std::string firstName )
	{
		strFirstName = firstName;
	}

	void setMiddleName ( std::string middleName )
	{
		strMiddleName = middleName;
	}

	void setLastName ( std::string lastName )
	{
		strLastName = lastName;
	}

	void setBalance ( double newBalance )
	{
		flCurrentBalance = newBalance;
	}

	void setTransactionReference ( Transaction_t *newRef )
	{
		currentTransaction = newRef;
	}

	bool isNull ( ) 
	{
		return ( ( strFirstName == "" ) || ( strMiddleName == "" ) || ( strLastName == "" ) || ( flCurrentBalance == 0.f ) || ( currentTransaction == nullptr ) );
	}
};