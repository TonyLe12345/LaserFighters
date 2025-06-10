#include <SFML/Graphics.hpp>
using namespace sf;
#include "player.h"
#include "laser.h"
#include <cmath>


void player::move_left(int speed) {
    shape->move(-speed, 0);
}
void player::move_right(int speed) {
    shape->move(speed, 0);
}

int player::get_x() {
    return shape->getPosition().x;
}

int player::get_y() {
    return shape->getPosition().y;
}

int player::get_depth() {
    return depth;
}

bool player::isHit(int target_x, int target_y, int target_depth) {
    if (bullet->isFired()) {
        if (bullet->isHit(target_x, target_y, target_depth)) {
            return true;
        }
    }
    return false;

}

player::player(int r, int x, int y)
{
    shape = new CircleShape();
    shape->setRadius(r); 
    shape->setPosition(x,y);
    shape->setFillColor(Color::Blue);
    shape->setOrigin(r/2,r/2);
    bullet = new laser();
    depth = r;

}

void player::fire() {
    if (bullet->yposition()) {
        bullet->reset();
    }

    if (bullet->isFired() == false) {
        bullet->use(shape->getPosition());
    }
}

void player::draw(RenderWindow* windo) {
    windo->draw(*shape);
    if (bullet->isFired()) {
        bullet->move(shape->getPosition().y);
        bullet->draw(windo);
    }
}

laser* player::get_bullet() {
    return bullet;
}