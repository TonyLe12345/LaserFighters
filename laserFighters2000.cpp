#include <iostream>

#include "laserFighters2000.h"
#include "DEFINITIONS.h"
#include "StateMachine.h"
#include "MainMenuState.h"
#include "GameOverState.h"
#include "Ship.h"
#include "goliath.h"
#include "flea.h"
#include "arachne.h"





laserFighters2000::laserFighters2000(GameDataRef data, int x, int y, std::string title, int _player1CharacterIndex, int _player2CharacterIndex)
    : _data(data), _player1CharacterIndex(_player1CharacterIndex), _player2CharacterIndex(_player2CharacterIndex)
{
    windo = &_data->window;
    //player (hitbox, radius, player x position, player y position, HP x position, HP y positions, TEXTURE_PATH, isFlipped, Health, Speed, FireRate)
    if (_player1CharacterIndex == 0 && _player2CharacterIndex == 0) {
        goliath* play1 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, GOLIATH_PATH, true, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        goliath* play2 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, GOLIATH_PATH, false, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 0 && _player2CharacterIndex == 1) {
        goliath* play1 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, GOLIATH_PATH, true, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        Arachne* play2 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, ARACHNE_PATH, false, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 0 && _player2CharacterIndex == 2) {
        goliath* play1 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, GOLIATH_PATH, true, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        Flea* play2 = new Flea(_data, FLEA_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, FLEA_PATH, false, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 1 && _player2CharacterIndex == 0) {
        Arachne* play1 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, ARACHNE_PATH, true, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        goliath* play2 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, FLEA_PATH, false, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 1 && _player2CharacterIndex == 1) {
        Arachne* play1 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, ARACHNE_PATH, true, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        Arachne* play2 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, ARACHNE_PATH, false, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 1 && _player2CharacterIndex == 2) {
        Arachne* play1 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, ARACHNE_PATH, true, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        Flea* play2 = new Flea(_data, FLEA_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, FLEA_PATH, false, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 2 && _player2CharacterIndex == 0) {
        Flea* play1 = new Flea(_data, FLEA_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, FLEA_PATH, true, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        goliath* play2 = new goliath(_data, GOLIATH_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, GOLIATH_PATH, false, GOLIATH_HEALTH, GOLIATH_SPEED, GOLIATH_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 2 && _player2CharacterIndex == 1) {
        Flea* play1 = new Flea(_data, FLEA_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, FLEA_PATH, true, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        Arachne* play2 = new Arachne(_data, ARACHNE_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, ARACHNE_PATH, false, ARACHNE_HEALTH, ARACHNE_SPEED, ARACHNE_FIRERATE);
        player1 = play1;
        player2 = play2;
    } else if (_player1CharacterIndex == 2 && _player2CharacterIndex == 2) {
        Flea* play1 = new Flea(_data, FLEA_HITBOX_RADIUS, P1_X_COORD, P1_Y_COORD, P1_HP_X_COORD, P1_HP_Y_COORD, FLEA_PATH, true, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        Flea* play2 = new Flea(_data, FLEA_HITBOX_RADIUS, P2_X_COORD, P2_Y_COORD, P2_HP_X_COORD, P2_HP_Y_COORD, FLEA_PATH, false, FLEA_HEALTH, FLEA_SPEED, FLEA_FIRERATE);
        player1 = play1;
        player2 = play2;
    }
    
}


void laserFighters2000::Init() {
    // Load the background texture
    _data->assets.LoadTexture("Play Screen Background", PLAY_SCREEN_BACKGROUND_FILEPATH);
    // Retrieve the background texture from the AssetManager
    sf::Texture& backgroundTexture = _data->assets.GetTexture("Play Screen Background");
    // Set the background texture for the sprite
    _background.setTexture(backgroundTexture);
    _background.setPosition(0, 0); // Set position as needed
}

void laserFighters2000::HandleInput()
{
    sf::Event event;
    while (windo->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            windo->close();
        }

        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            // Go back to the main menu state
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
        
    }

    // Player 1 movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1->get_x() > 170)
    {
        player1->move_left(10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player1->get_x() < static_cast<int>(windo->getSize().x)-170)
    {
        player1->move_right(10);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player1->fire();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player1->ability(); 
    }
    

    // Player 2 movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player2->get_x() > 170)
    {
        player2->move_left(10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player2->get_x() < static_cast<int>(windo->getSize().x)-170)
    {
        player2->move_right(10);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player2->fire();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player2->ability();
    }
    
}

void laserFighters2000::Update(float frameRate)
{
    // Check for collisions and update game logic
    for (auto bullet : player1->get_bullets()) {
        if (bullet->isFired() && bullet->isHit(player2->get_x(), player2->get_y(), player2->get_depth())) {
            bullet->reset_position(-1, -1);
            player2->takeDamage(10); // Reduce health by 10 
            std::cout << "Player 1 hit Player 2!" << std::endl;
        }
    }

    for (auto bullet : player2->get_bullets()) {
        if (bullet->isFired() && bullet->isHit(player1->get_x(), player1->get_y(), player1->get_depth())) {
            bullet->reset_position(-1, -1);
            player1->takeDamage(10); // Reduce health by 10 
            std::cout << "Player 2 hit Player 1!" << std::endl;
        }
    }

    // Check if a player has won
    if (player1->getHealth() <= 0)
    {
        _data->machine.AddState(StateRef(new GameOverState(_data, "Player 2")), true);
    }
    else if (player2->getHealth() <= 0)
    {
        _data->machine.AddState(StateRef(new GameOverState(_data, "Player 1")), true);
    }
}

void laserFighters2000::Draw(float frameRate)
{
    windo->clear();
    windo->draw(_background);
    player1->draw(windo);
    player2->draw(windo);
    windo->display();
}

laserFighters2000::~laserFighters2000()
{
    delete player1;
    delete player2;
}
