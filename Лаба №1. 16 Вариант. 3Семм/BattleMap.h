#pragma once
#include "macros.h"
#include <vector>
#include "FirstTypeShip.h"
#include "SecondTypeShip.h"

class BattleMap
{
public:
	BattleMap();
	~BattleMap();

	inline void insert_ship(FirstTypeShip& addingShip);
	inline void insert_ship(SecondTypeShip& addingShip);



private:
	std::vector <FirstTypeShip> ShipArrayFirstType;
	std::vector <SecondTypeShip> ShipArraySecondType;
	int OurMap[SIZE_Y][SIZE_X];
	
	inline void make_null_area();

};

