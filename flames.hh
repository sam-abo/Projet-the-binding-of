#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "salle.hh" // Assuming salle is a class representing a room or area in the game
#include "enemy.hh" // Assuming Enemy is a class representing an enemy

class Flames {
public:
    Flames();
    Flames(sf::Vector2f origin, const salle* room, float intensity, float spreadSpeed);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;

    // Method to initiate throwing flames
    void throwFlames(sf::Vector2f targetPosition);
    void throwFlamesNearby(const std::vector<Enemy>& enemies, float range);

protected:
    sf::Vector2f origin;
    const salle* currentRoom;
    float intensity;  // Represents the strength or damage potential of the flames
    float spreadSpeed;  // The rate at which the flames spread
    sf::CircleShape flameShape;  // Graphical representation of the flames
};
