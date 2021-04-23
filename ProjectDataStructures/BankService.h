#pragma once

#include <math.h>
#include <vector>
#include <string>

namespace BankService {
	const std::vector < std::string> NAMES_LIST = { "Addison", "Adrian", "Alex", "Arden", "Aubrey", "August", "Bailey", "Blair", "Blaine", "Brett", "Britton", "Cameron", "Carey", "Casey", "Charlie", "Dakota", "Dallas", "Dana", "Devin", "Drew", "Elliott", "Emery", "Evelyn", "Finley", "Gray", "Hayden", "Jamie", "Jesse", "Jude", "Kai", "Kelly", "Kennedy", "Kit", "Lane", "London", "Madison", "Mackenzie", "Marley", "Marlow", "Morgan", "Peyton", "Quinn", "Reese", "Robin", "Rory", "Rowan", "River", "Scout", "Shiloh", "Sidney", "Skye", "Sloane", "Tate", "Taylor", "Teagan", "Tiernan", "Tracy", "Tyler", "Windsor", "Winter", "Wyatt" };

	bool randomBool ( )
	{
		return rand ( ) > ( RAND_MAX / 2 );
	}

	int getRandomInt ( const int limit )
	{
		return rand ( ) % limit - 1;
	}
}