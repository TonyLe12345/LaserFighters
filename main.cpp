#include <SFML/Graphics.hpp>
using namespace sf;
#include "laserFighters2000.h"
#include "player.h"

int main() {
    laserFighters2000 game(1000, 600, "LASER FIGHTERS 2000");
    game.run(1000);
    return 0;
}