#ifndef ROCK_HH
#define ROCK_HH

#include <SFML/Graphics.hpp>
#include <cmath> //

class Rock {
public:
    Rock(float radius, sf::Color color, sf::Vector2f position, sf::Vector2f target);
    void update(float deltaTime);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    
};

#endif // ROCK_HH