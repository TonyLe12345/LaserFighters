#include <SFML/Graphics.hpp>
using namespace sf;
#include "laser.h"
#pragma once

class player
{
protected:
    CircleShape* shape;
    laser* bullet;
    int depth;
public:
    player(int r, int x, int y);
    void move_left(int speed);
    void move_right(int speed);
    void draw(RenderWindow* windo);
    void fire();
    int get_x();
    int get_y();
    int get_depth();
    laser* get_bullet();
    bool isHit(int target_x, int target_y, int target_depth);
    ~player();
};


