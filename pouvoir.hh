#ifndef POUVOIR_HH
#define POUVOIR_HH

#include <SFML/Graphics.hpp>
#include <cmath> 

class Pouvoir {
public:
    enum class Type {
        RockThrowing, // Common in both Hero and Enemy
        Flames, // Specific to Enemy
        Invisibility, // Example from your base class
        SwordStriking, // Common in both Hero and Enemy
        BloodRegeneration, // Specific to Hero
        Shield // Specific to Hero
    };

    Pouvoir(Type type, sf::Vector2f position, sf::Vector2f target = sf::Vector2f());

    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window) const;
    Type getType() const;

protected:
    Type type;
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool isVisible;

    // Common update methods
    void updateRockThrowing(float deltaTime) = 0;
    void updateFlames(float deltaTime) = 0;
    void updateInvisibility(float deltaTime) = 0;
    void updateSwordStriking(float deltaTime) = 0;
    // Hero-specific update methods
    void updateBloodRegeneration(float deltaTime) = 0;
    void updateShield(float deltaTime) = 0;

    // Additional methods as needed
};

#endif // POUVOIR_HH
