#pragma once
#include "macros.h"
#include <vector>
#include <set>
#include "FirstTypeShip.h"
#include "SecondTypeShip.h"


/*
	Справка по карте:
	0- изначальное значение карты
	1- корабль первого типа
	2- корабль второго типа
	3- корабль трётьего типа
	4- корабль четвёртого типа
	5- зона корабля
	6- промах
*/

class BattleMap
{
public:
	BattleMap();
	~BattleMap();

	inline bool hit_check(std::pair <int, int>& OurHit);
	inline bool hit_check(int& x, int& y);
	inline void insert_ship_firstType();
	inline void insert_ship_secondType();
	inline void insert_ship_thirdType();
	inline void insert_ship_fourthType();

private:
	std::vector <FirstTypeShip> ShipArrayFirstType;
	std::vector <SecondTypeShip> ShipArraySecondType;
	int OurMap[SIZE_Y][SIZE_X];
	std::set <std::pair <int, int> > FreeSpace;

};

