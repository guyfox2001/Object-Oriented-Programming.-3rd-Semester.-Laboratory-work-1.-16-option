#include "SeaBattleGame.h"

SeaBattleGame::SeaBattleGame()
{
	this->BattleMapFirstPlayer = new int* [SIZE_Y];
	for (int i = 0; i < SIZE_Y; ++i) {
		this->BattleMapFirstPlayer[i] = new int[SIZE_X];
	}
	this->BattleMapSecondPlayer = new int* [SIZE_Y];
	for (int i = 0; i < SIZE_Y; ++i) {
		this->BattleMapFirstPlayer[i] = new int[SIZE_X];
	}
	this->players_priority = 1;

}

SeaBattleGame::SeaBattleGame(string player1, string player2)
{
	this->BattleMapFirstPlayer = new int* [SIZE_Y];
	for (int i = 0; i < SIZE_Y; ++i) {
		this->BattleMapFirstPlayer[i] = new int[SIZE_X];
	}
	this->BattleMapSecondPlayer = new int* [SIZE_Y];
	for (int i = 0; i < SIZE_Y; ++i) {
		this->BattleMapFirstPlayer[i] = new int[SIZE_X];
	}
	this->players_priority = 1;

	this->first_player = player1;
	this->second_player = player2;
}

SeaBattleGame::~SeaBattleGame()
{
	delete[] this->BattleMapFirstPlayer;
	this->first_player.clear();
	this->second_player.clear();
	delete &this->players_priority;
}

inline void SeaBattleGame::shoot()
{
	int x, y;
	switch (this->players_priority) {
	case 1:
		
		while (true) {
			cout << "Введите координаты выстрела X, Y\n";
			cin >> x >> y;
			if (x > 10 || y > 10) {
				cerr << "Введено не верное значение\n";
				continue;
			}
			if (this->BattleMapFirstPlayer[x - 1][y-1] == 99) {
				cerr << "Выстрел в эту клетку уже был произведён или там находится зона убитого корабля\n";
				continue;
			}
			if (x < 10 && y < 10 && this->BattleMapFirstPlayer[x - 1][y - 1] != 99) {
				cout << "Выстрел произведён\n";
				// сделать граммтоную проверку попаданий
				break;
			}
		}
	case 2:
		while (true) {
			cout << "Введите координаты выстрела X, Y\n";
			cin >> x >> y;
			if (x > 10 || y > 10) {
				cerr << "Введено не верное значение\n";
				continue;
			}
			if (this->BattleMapSecondPlayer[x - 1][y - 1] == 99) {
				cerr << "Выстрел в эту клетку уже был произведён или там находится зона убитого корабля\n";
				continue;
			}
			if (x < 10 && y < 10 && this->BattleMapSecondPlayer[x - 1][y - 1] != 99) {
				cout << "Выстрел произведён\n";
				break;
			}
		}
	}
}

inline bool SeaBattleGame::hit_to_ship(int& x, int& y)
{
	switch (this->players_priority)
	{
	case 1:
		switch (this->BattleMapFirstPlayer[x - 1][y - 1]) {
		case NULL: 
			return false;
		case FIRST_TYPE: 
			return true;
		case SECOND_TYPE: 
			return true;
		case THIRD_TYPE: 
			return true;
		case FOURTH_TYPE: 
			return true;
		}
	case 2:
		switch (this->BattleMapSecondPlayer[x - 1][y - 1]) {
		case NULL: 
			return false;
		case FIRST_TYPE:
			return true;
		case SECOND_TYPE:
			return true;
		case THIRD_TYPE:
			return true;
		case FOURTH_TYPE:
			return true;
		}
	}
}

inline bool SeaBattleGame::ship_is_dead(int& x, int& y)
{
	switch (this->players_priority)
	{
	case 1:
		switch (this->BattleMapFirstPlayer[x-1][y-1])
		{
		case FIRST_TYPE:
			return true;
		case SECOND_TYPE:

		}
		break;
	case 2:

		break;
	}
}

