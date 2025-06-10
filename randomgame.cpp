#include <SFML/Graphics.hpp>
using namespace sf;

void move_left(CircleShape& a) {
    Vector2f pose = a.getPosition();
    pose.x = pose.x - 10;
    a.setPosition(pose);
}
void move_right(CircleShape& a) {
    Vector2f pose = a.getPosition();
    pose.x = pose.x + 10;
    a.setPosition(pose);
}

int main()
{
    RenderWindow window(VideoMode(1000, 600), "LASER FIGHTERS 2000");
    
    CircleShape shape(10.f);
    shape.setFillColor(Color::Blue);
    shape.setOrigin(Vector2f(5,5));
    shape.setPosition(Vector2f(500,50));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // left key is pressed: move our character
                move_left(shape);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            {
                // right key is pressed: move our character
                move_right(shape);
            }
                
        }

        

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}