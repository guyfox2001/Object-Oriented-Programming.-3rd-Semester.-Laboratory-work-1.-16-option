#include "FirstTypeShip.h"

inline void FirstTypeShip::set_coords(int& x, int& y)
{
	this->COORDS.insert(std::make_pair(x, y));
}

inline std::set<std::pair<int, int>>& FirstTypeShip::get_coords()
{
	return this->COORDS;
}

inline bool FirstTypeShip::check_alive()
{
	if (this->IsAlive) return true;
	else return false;
}

inline void FirstTypeShip::rotate_dmg(int& x, int& y)
{
	for (auto IT = this->COORDS.begin(); IT != this->COORDS.end(); ++IT) {
		if (IT->first == x && IT->second == y) {
			this->COORDS_DMG.insert(*IT);
			this->COORDS.erase(*IT);
		}
	}
	if (this->COORDS.size() == 0) {
		this->IsAlive = false;
	}
}

inline bool FirstTypeShip::isShoted(int& x, int& y)
{
	if (this->COORDS.find(std::make_pair(x, y)) != this->COORDS.end()) return true;
	else return false;
}


FirstTypeShip::FirstTypeShip()
{
	
}

FirstTypeShip::~FirstTypeShip()
{
	delete &this->COORDS;
	delete &this->COORDS_DMG;
	delete &this->IsAlive;
}
