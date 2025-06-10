#include <SFML/Graphics.hpp>
using namespace sf;
#include "player.h"

class laserFighters2000
{
private:
    RenderWindow* windo;
    player* player1;
    player* player2;
public:
    laserFighters2000(int x, int y, std::string title);
    void run(int x);
    ~laserFighters2000();
};