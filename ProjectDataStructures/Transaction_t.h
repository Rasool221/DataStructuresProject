#pragma once

#include "TransactionType.h"

struct Transaction_t {
	int transactionType;
	double flTransactionAmount;

	Transaction_t ( )
	{
		flTransactionAmount = 0.f;
	}

	void setTransactionAmount ( double newAmt )
	{
		flTransactionAmount = newAmt;
	}

	void setTransactionType ( int newTransactionType )
	{
		transactionType = newTransactionType;
	}
};