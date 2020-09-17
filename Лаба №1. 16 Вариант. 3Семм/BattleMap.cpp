#include "BattleMap.h"

inline void BattleMap::insert_ship(FirstTypeShip& addingShip)
{
	try {
		if (this->ShipArrayFirstType.size() == 4) throw SO_MUCH_SHIPS;
	}
	catch (int Exep) {
		switch (Exep){
		case SO_MUCH_SHIPS:

		}
	}
}
