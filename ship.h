#include <SFML/Graphics.hpp>
#include "player.h"


using namespace sf;

class Ship : public player {
    private:
    int hp = 0;
    int spd;
    int fireRate;

    public:
    void ability() {};
    
    Ship(int r, int x, int y) : player(r, x, y) {}
    ~Ship(){}

    int getHP(){
        return hp;
    }
    void setHP(int h){
        hp = h;
    }

    int getSPD(){
        return spd;
    }
    void setSPD(int s){
        spd = s;
    }

    int getFireRate(){
        return fireRate;
    }
    void setFireRate(int fr){
        fireRate = fr;
    }

    
};