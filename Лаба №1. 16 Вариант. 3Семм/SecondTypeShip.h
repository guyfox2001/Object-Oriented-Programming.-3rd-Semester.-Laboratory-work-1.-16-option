#pragma once
#include "Ships.h"
class SecondTypeShip :
    public Ships
{
public:
    inline void set_coords(std::set<std::pair <int,int> >& OurCoords);
    inline std::set<std::pair <int, int> >& get_coords();
    inline bool check_alive();
    inline void rotate_dmg(int& x, int& y);
    inline bool isShoted(int& x, int& y);

    SecondTypeShip(std::set<std::pair <int, int> >& OurCoords);
    SecondTypeShip();
    ~SecondTypeShip();
};

