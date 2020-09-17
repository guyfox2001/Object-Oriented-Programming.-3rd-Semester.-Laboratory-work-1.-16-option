#include "SecondTypeShip.h"

inline void SecondTypeShip::set_coords(std::set<std::pair<int, int>>& OurCoords)
{
	this->COORDS = OurCoords;
}

inline std::set<std::pair<int, int>>& SecondTypeShip::get_coords()
{
	return this->COORDS;
}

inline bool SecondTypeShip::check_alive()
{
	if (this->IsAlive) return true;
	else return false;
}

inline void SecondTypeShip::rotate_dmg(int& x, int& y)
{
	for (auto IT = this->COORDS.begin(); IT != this->COORDS.end(); IT++) {
		if (IT->first == x && IT->second == y) {
			this->COORDS_DMG.insert(*IT);
			this->COORDS.erase(*IT);
		}
	}
	if (this->COORDS.empty()) this->IsAlive = false;
}

inline bool SecondTypeShip::isShoted(int& x, int& y)
{
	if (this->COORDS.find(std::make_pair(x, y)) != this->COORDS.end()) return true;
	else return false;
}

SecondTypeShip::SecondTypeShip(std::set<std::pair <int, int> >& OurCoords) {
	this->COORDS = OurCoords;
	this->IsAlive = true;
}
SecondTypeShip::SecondTypeShip() {

}

SecondTypeShip::~SecondTypeShip()
{
}
