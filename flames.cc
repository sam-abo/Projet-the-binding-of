
#include "Flames.hh"

Flames::Flames() : origin(sf::Vector2f(0, 0)), currentRoom(nullptr), intensity(0), spreadSpeed(0) {
    flameShape.setRadius(0);
    flameShape.setFillColor(sf::Color::Red);  // Default color for flames
}

Flames::Flames(sf::Vector2f origin, const salle* room, float intensity, float spreadSpeed)
    : origin(origin), currentRoom(room), intensity(intensity), spreadSpeed(spreadSpeed) {
    flameShape.setRadius(intensity);  //
    flameShape.setFillColor(sf::Color::Red);  // F
    flameShape.setPosition(origin);
}


void Flames::update(float deltaTime) {
    // Increase the size of the flame based on spreadSpeed
    float newRadius = flameShape.getRadius() + spreadSpeed * deltaTime;
    flameShape.setRadius(newRadius);

    // fix damage on character / ennemies
}

void Flames::draw(sf::RenderWindow& window) const {
    window.draw(flameShape);  // Render the flame shape
}

void Flames::throwFlames(sf::Vector2f direction, float throwSpeed) {
    // Set the initial direction and speed for the flame throw
    this->direction = direction;
    this->throwSpeed = throwSpeed;

    // Example: Move the flame in the set direction at the set speed
    sf::Vector2f newPosition = flameShape.getPosition() + direction * throwSpeed;
    flameShape.setPosition(newPosition);

    // fix damage on character / ennemies
}


void Flames::throwFlamesNearby(const std::vector<Enemy>& enemies, float range) {
    // Example: Throw flames at all enemies within range
    for (const Enemy& enemy : enemies) {
        // Calculate the distance between the flame and the enemy
        float distance = sqrt(pow(flameShape.getPosition().x - enemy.getPosition().x, 2) +
                              pow(flameShape.getPosition().y - enemy.getPosition().y, 2));

        // If the enemy is within range, throw flames at it
        if (distance <= range) {
            throwFlames(enemy.getPosition() - flameShape.getPosition(), throwSpeed);
        }
    }
}

