#include <SFML/Graphics.hpp>
using namespace sf;
#pragma once

class laser
{
private:
    RectangleShape* shape;
    bool fired;
    int depth;
public:
    laser();
    void draw(RenderWindow* windo);
    void move(int num);
    void set_position(Vector2f position);
    bool isFired();
    void use (Vector2f position);
    bool yposition();
    void reset();
    int get_x();
    int get_y();
    int get_depth();
    bool isHit(int target_x, int target_y, int target_depth);
    void reset_position(int x, int y);
    ~laser();
};



