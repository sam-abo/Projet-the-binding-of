#ifndef POUVOIR_HH
#define POUVOIR_HH

#include <SFML/Graphics.hpp>
#include <cmath> // For sqrt and other math functions

class Pouvoir {
public:
    enum class Type {
        RockThrowing,
        Flames,
        Invisibility
    };

    Pouvoir(Type type, sf::Vector2f position, sf::Vector2f target = sf::Vector2f());

    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    Type getType() const;

private:
    Type type;
    sf::CircleShape shape; // Used for RockThrowing and Flames
    sf::Vector2f velocity; // Used for RockThrowing
    bool isVisible;        // Used for Invisibility

    void updateRockThrowing(float deltaTime);
    void updateFlames(float deltaTime);
    void updateInvisibility(float deltaTime);
};

#endif // POUVOIR_HH

