#pragma once

#include "TransactionType.h"

struct Transaction_t {
	TransactionType transactionType;
	double flTransactionAmount;

	void setTransactionAmount ( double newAmt )
	{
		flTransactionAmount = newAmt;
	}

	void setTransactionType ( TransactionType newTransactionType )
	{
		transactionType = newTransactionType;
	}
};