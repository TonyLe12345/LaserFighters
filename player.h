#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>

#include "laser.h"
#include "healthbar.h"
#include "Game.h"
#include "GameState.h"


using namespace sf;


class player
{
protected:
    GameDataRef _data;
    CircleShape* shape;
    sf::Sprite sprite;
    std::vector<laser*> bullets;
    int depth;
    healthbar* hpBar; 
    int health;
    int speed;
    std::chrono::steady_clock::time_point lastFiredTime;
    int HP_x, HP_y;
    bool isFlipped;
    int fireRate;
    
public:
    player(GameDataRef data, int r, int x, int y, int HP_x, int HP_y, 
        const std::string& texturePath, bool isFlipped, int fireRate);

    void move_left(int speed);
    void move_right(int speed);
    void draw(RenderWindow* windo);
    void fire();
    void takeDamage(int amount);
    int get_x();
    int get_y();
    int get_depth();
    laser* get_bullet();
    std::vector<laser*> get_bullets();
    bool isHit(int target_x, int target_y, int target_depth);
    void setHealth(int health);
    int getHealth() const;
    virtual int getSpeed() const;
    virtual void ability() = 0;
    
    virtual ~player();
};


