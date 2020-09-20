#pragma once
#include "macros.h"
#include <vector>
#include <set>
#include "FirstTypeShip.h"
#include "SecondTypeShip.h"


/*
	������� �� �����:
	0- ����������� �������� �����
	1- ������� ������� ����
	2- ������� ������� ����
	3- ������� ������� ����
	4- ������� ��������� ����
	5- ���� �������
	6- ������
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

