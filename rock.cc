#include "rock.hh"

// Constructor
Rock::Rock(float radius, sf::Color color, sf::Vector2f position, sf::Vector2f target) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(position);

    // Calculate velocity vector pointing from the rock's position to the target
    sf::Vector2f direction = target - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    velocity = direction / length; // Normalize the direction
}

// Update method
void Rock::update(float deltaTime) {
    // Update the position of the rock based on its velocity
    shape.move(velocity * deltaTime);
}

// You might also want to add methods to get the shape for rendering and collision detection
const sf::CircleShape& Rock::getShape() const {
    return shape;
}
