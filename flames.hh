#pragma once
#include <SFML/Graphics.hpp>
#include "salle.hh" // Assuming salle is a class representing a room or area in the game

class Flames {
public:
    Flames();
    Flames(sf::Vector2f origin, const salle* room, float intensity, float spreadSpeed);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;

    // Method to initiate throwing flames
    void throwFlames(sf::Vector2f direction, float throwSpeed);

protected:
    sf::Vector2f origin;
    const salle* currentRoom;
    float intensity;  // Represents the strength or damage potential of the flames
    float spreadSpeed;  // The rate at which the flames spread
    sf::CircleShape flameShape;  // Graphical representation of the flames

    // Additional properties for throwFlames method
    sf::Vector2f direction; // Direction in which the flames are thrown
    float throwSpeed; // Speed at which the flames are thrown
};
