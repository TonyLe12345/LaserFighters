#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <chrono>

#include "player.h"
#include "AssetManager.h"
#include "DEFINITIONS.h"



using namespace sf;


void player::move_left(int speed) {
    sprite.move(-speed, 0);
}
void player::move_right(int speed) {
    sprite.move(speed, 0);
}

int player::get_x() {
    return sprite.getPosition().x;
}

int player::get_y() {
    return sprite.getPosition().y;
}

int player::get_depth() {
    return depth;
}

bool player::isHit(int target_x, int target_y, int target_depth) {
    for (auto bullet : bullets) {
        if (bullet->isFired() && bullet->isHit(target_x, target_y, target_depth)) {
            return true;
        }
    }
    return false;
}

player::player(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, 
               const std::string& texturePath, bool isFlipped, int fireRate)     
                : _data(data), health(200), lastFiredTime(std::chrono::steady_clock::now()), fireRate(fireRate)
    
{

    //create a circle for the hit-box
    shape = new CircleShape();
    shape->setRadius(r); 
    shape->setPosition(x,y);
    shape->setFillColor(Color::Blue);
    shape->setOrigin(r/2,r/2);
    depth = r;



    // Load the texture using the AssetManager
    _data->assets.LoadTexture("ship sprite", texturePath);
    sf::Texture& texture = _data->assets.GetTexture("ship sprite");
    sprite.setTexture(texture);

    sprite.setPosition(x, y);
    
    // Set the origin to the center of the sprite
    sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);

    // Flip the sprite if needed
    if (isFlipped) {
    sprite.setScale(1.f, -1.f);
    }


    // HP bar position and size.
    hpBar = new healthbar(HP_x, HP_y, 80, 20, health); 

}

void player::fire() 
{
    auto now = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastFiredTime).count();
    //cout << "time Diff is: "<< timeDiff << endl;
    //cout << "fireRate is: "<< fireRate << endl;
    if (timeDiff >= fireRate) {
        laser* newBullet = new laser();
        newBullet->use(sprite.getPosition());
        bullets.push_back(newBullet);
        lastFiredTime = now;
    } //else{cout << "did not fire"<< endl;}
}



void player::draw(RenderWindow* windo) {
    windo->draw(sprite);

    // Draw each bullet
    for (auto bullet : bullets) {
        if (bullet->isFired()) {
            bullet->move(sprite.getPosition().y);
            bullet->draw(windo);
        }
    }
    
    hpBar->draw(*windo);
}

std::vector<laser*> player::get_bullets() {
    return bullets;
}

void player::takeDamage(int amount) {
    this->health -= amount;
    if (health < 0) health = 0;
    hpBar->setHealth(health);
}

player::~player() {
    for (auto bullet : bullets) {
        delete bullet;
    }
    delete shape;
    delete hpBar;
}
void player::setHealth(int health) {
    this->health = health;
}

int player::getHealth() const {
    return health;
}

int player::getSpeed() const {
    std::cout << speed << std::endl;
    return speed;
}

