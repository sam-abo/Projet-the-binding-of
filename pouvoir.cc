#include "pouvoir.hh"

Pouvoir::Pouvoir(Type type, sf::Vector2f position, sf::Vector2f target)
    : type(type), isVisible(true) {
    shape.setPosition(position);
    if (type == Type::RockThrowing) {
        shape.setRadius(5.0f);
        shape.setFillColor(sf::Color::Black);

        sf::Vector2f direction = target - position;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        velocity = direction / length;
    } else if (type == Type::Flames) {
        shape.setRadius(10.0f);
        shape.setFillColor(sf::Color::Red);
    }
    // Other types can be initialized similarly
}

void Pouvoir::update(float deltaTime) {
    switch (type) {
        case Type::RockThrowing:
            shape.move(velocity * deltaTime);
            break;
        case Type::Flames:
            // Update flames (e.g., flickering effect)
            break;
        case Type::Invisibility:
            // Update invisibility (e.g., toggle visibility)
            break;
        case Type::SwordStriking:
            // Update sword striking (e.g., animation or effect)
            break;
    }
}

void Pouvoir::draw(sf::RenderWindow& window) const {
    if (type != Type::Invisibility && isVisible) {
        window.draw(shape);
    }
}

Pouvoir::Type Pouvoir::getType() const {
    return type;
}
