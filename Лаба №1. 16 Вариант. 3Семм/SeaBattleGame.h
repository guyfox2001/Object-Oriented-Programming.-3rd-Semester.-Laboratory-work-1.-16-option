#include "header_includes.h"
#include "macros.h"

class SeaBattleGame
{
public:
	SeaBattleGame();
	SeaBattleGame(string player1, string player2);
	~SeaBattleGame();
	inline void shoot();
	inline void insert_ship();
	inline void start();
	inline void stop();
	inline void score();

	
	//sets and gets
	inline string& get_player();

private:
	inline bool hit_to_ship(int&x, int&y);
	inline bool ship_is_dead(int& x, int& y);
	inline void set_first_player(string& setting_player);
	inline void set_second_player(string& setting_player);
	int** BattleMapFirstPlayer; // Класс для карты
	int** BattleMapSecondPlayer; // Класс для карты 
	string first_player, second_player;
	uint8_t players_priority;
};
