#pragma once
#include <set>
#include <iterator>

class Ships
{
protected:
	std::set <std::pair <int, int> > COORDS;
	std::set <std::pair <int, int> > COORDS_DMG;
	bool IsAlive;
public:
	virtual void set_coords();
	virtual std::set<std::pair <int, int> >& get_coords();
	virtual bool check_alive();
	virtual void rotate_dmg();
	virtual bool isShoted();

};

