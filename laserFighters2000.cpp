#include <SFML/Graphics.hpp>
using namespace sf;
#include "laserFighters2000.h"
#include "player.h"
#include <iostream>
#include "ship.h"

laserFighters2000::laserFighters2000(int x, int y, std::string title)
{
    windo = new RenderWindow(VideoMode(x, y), title);
    player1 = new Ship(10,500,50);
    player2 = new Ship(10,500,550);
}

void laserFighters2000::run(int x) {
    while (windo->isOpen())
    {
        Event event;
        while (windo->pollEvent(event))
        {
            if (event.type == Event::Closed) {
                windo->close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1->get_x() > 0)
            {
                // left key is pressed: move our character
                player1->move_left(10);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && player1->get_x() < x)
            {
                // right key is pressed: move our character
                player1->move_right(10);
            }   

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                // left key is pressed: move our character
                player1->fire();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player2->get_x() > 0)
            {
                // left key is pressed: move our character
                player2->move_left(10);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) && player2->get_x() < x)
            {
                // right key is pressed: move our character
                player2->move_right(10);
            }     

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                // left key is pressed: move our character
                player2->fire();
            }     
        }

        

        if (player1->get_bullet()->isFired()) {
            if (player1->isHit(player2->get_x(), player2->get_y(), player2->get_depth())) {
                player1->get_bullet()->reset_position(-1,-1);
                int health = player2->getHP();
                health = health - player1->get_bullet()->get_damage();
                player2->setHP(health);
                std::cout << "Player 1 hit Player 2!" << std::endl;
                }
            }
            
        if (player2->get_bullet()->isFired()) {
            if (player2->isHit(player1->get_x(), player1->get_y(), player1->get_depth())) {
                player1->get_bullet()->reset_position(-1,-1);
                int health = player1->getHP();
                health = health - player2->get_bullet()->get_damage();
                player1->setHP(health);
                std::cout << "Player 2 hit Player 1!" << std::endl;
                }
}

        windo->clear();
        player1->draw(windo);
        player2->draw(windo);
        windo->display();
    }
}

laserFighters2000::~laserFighters2000()
{
}
