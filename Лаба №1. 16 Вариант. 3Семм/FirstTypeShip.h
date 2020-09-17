#pragma once
#include "Ships.h"
class FirstTypeShip :
    public Ships
{
public:
    inline void set_coords(int& x, int& y);
    inline std::set<std::pair <int, int> >& get_coords();
    inline bool check_alive();
    inline void rotate_dmg(int& x, int&y);
    inline bool isShoted(int&x, int&y);

    FirstTypeShip();
    FirstTypeShip(int&x, int&y);
    ~FirstTypeShip();
};

