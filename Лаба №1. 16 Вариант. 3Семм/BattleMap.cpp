#include "BattleMap.h"
#include <iostream>

BattleMap::BattleMap()
{
	for (int i = 0; i < SIZE_Y; i++) {
		for (int j = 0; j < SIZE_X; j++) {
			this->FreeSpace.insert(std::make_pair(i, j));
			this->OurMap[i][j] = 0;
		}
	}
}

inline bool BattleMap::hit_check(std::pair<int, int>& OurHit)
{
	if (this->FreeSpace.find(OurHit) != this->FreeSpace.end()) return false;
	else return true;
}

inline bool BattleMap::hit_check(int& x, int& y)
{
	if (this->FreeSpace.find(std::make_pair(x,y)) != this->FreeSpace.end()) return false;
	else return true;
}

inline void BattleMap::insert_ship_firstType()
{
	setlocale(LC_ALL, "Rus");
	int x, y;
	bool break_while = false;
	while (!break_while)
	{
		std::cout << "Введите значения X, Y\n";
		std::cin >> y >> x;

		switch (this->OurMap[y--][x--])
		{
		case 0:
			break_while = true;
			break;
		case 1:
			std::cout << "Здесь находится корабль первого типа\n";
			break;
		case 2:
			std::cout << "Здесь находится корабль второго типа\n";
			break;
		case 3:
			std::cout << "Здесь находится корабль третьего типа\n";
			break;
		case 4:
			std::cout << "Здесь находится корабль четвёртого типа\n";
			break;
		case 5:
			std::cout << "Здесь находится зона корабля\n";
			break;
		case 6:
			std::cout << "В эту точку уже был выстрел\n";
			break;
		default:
			std::cout << "введены не верные значения\n";
			break;
		}
	}
	FirstTypeShip addingShip(x,y);
	this->OurMap[y][x] = 1;
	if (x + 1 < SIZE_X) this->OurMap[y][x+1] = 5;
	if (x - 1 < SIZE_X) this->OurMap[y][x-1] = 5;
	if (y + 1 < SIZE_Y) this->OurMap[y+1][x] = 5;
	if (y - 1 < SIZE_Y) this->OurMap[y-1][x] = 5;
	if (x + 1 < SIZE_X && y + 1 < SIZE_Y) this->OurMap[y + 1][x + 1] = 5;
	if (x + 1 < SIZE_X && y - 1 < SIZE_Y) this->OurMap[y - 1][x + 1] = 5;
	if (x - 1 < SIZE_X && y + 1 < SIZE_Y) this->OurMap[y + 1][x - 1] = 5;
	if (x - 1 < SIZE_X && y - 1 < SIZE_Y) this->OurMap[y - 1][x - 1] = 5;
}

inline void BattleMap::insert_ship_secondType()
{
	setlocale(LC_ALL, "Rus");
	int x, y;
	bool break_while = false;
	std::set <std::pair <int, int> > addingCoords;
	while (!break_while)
	{
		std::cout << "Введите значения X, Y\n";
		std::cin >> y >> x;

		switch (this->OurMap[y--][x--])
		{
		case 0:
			break_while = true;
			break;
		case 1:
			std::cout << "Здесь находится корабль первого типа\n";
			break;
		case 2:
			std::cout << "Здесь находится корабль второго типа\n";
			break;
		case 3:
			std::cout << "Здесь находится корабль третьего типа\n";
			break;
		case 4:
			std::cout << "Здесь находится корабль четвёртого типа\n";
			break;
		case 5:
			std::cout << "Здесь находится зона корабля\n";
			break;
		case 6:
			std::cout << "В эту точку уже был выстрел\n";
			break;
		default:
			std::cout << "введены не верные значения\n";
			break;
		}
	}
	SecondTypeShip addingShip(addingCoords);
	for (auto it = addingShip.get_coords().begin(); it != addingShip.get_coords().end(); it++) {
		
	}
}
