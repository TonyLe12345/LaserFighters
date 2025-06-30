#include <SFML/Graphics.hpp>
#include <math.h>
using namespace sf;
#include "laser.h"

laser::laser()
{
    shape = new RectangleShape(Vector2f(5,10));
    shape->setFillColor(Color::Magenta);
    shape->setPosition(-1,-1);
    fired = false;
    depth = 10/2;
}

void laser::draw(RenderWindow* windo)
{
    windo->draw(*shape);
}

void laser::set_position(Vector2f position) {
    shape->setPosition(position);
}

void laser::use(Vector2f position) {
    shape->setPosition(position);
    fired = true;
}

bool laser::isFired() {
    return fired;
};

void laser::move(int num) {
    if (num<500) {
        shape->move(0,4);
    } else {
        shape->move(0,-4);
    }    
}

bool laser::yposition() {
    if (shape->getPosition().y > 600 || shape->getPosition().y < 0) {
        return true;
    } else {
        return false;
    }
}

int laser::get_x() {
    return shape->getPosition().x;
}

int laser::get_y() {
    return shape->getPosition().y;
}


int laser::get_depth() {
    return depth;
}


bool laser::isHit(int target_x, int target_y, int target_depth) {
    int x = get_x();
    int y = get_y();
    float d = sqrt((x - target_x)*(x - target_x) + (y - target_y)*(y - target_y));
    if (d < (depth + target_depth)) {
        return true;
    } else {
        return false;
    }

}

void laser::reset() {
    fired = false;
};

void laser::reset_position(int x, int y) {
    shape->setPosition(x,y);
};


laser::~laser() {
    delete shape;
}