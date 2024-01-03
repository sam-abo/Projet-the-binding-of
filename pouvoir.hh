#include "pouvoir.hh"

// Constructor
Pouvoir::Pouvoir(Type type, sf::Vector2f position, sf::Vector2f target)
    : type(type), isVisible(true) {
    switch (type) {
        case Type::RockThrowing:
            shape.setRadius(5.0f);
            shape.setFillColor(sf::Color::Black);
            shape.setPosition(position);

            // Calculate velocity vector pointing from the position to the target
            sf::Vector2f direction = target - position;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            velocity = direction / length; // Normalize the direction
            break;

        case Type::Flames:
            shape.setRadius(10.0f); // Example size for flame
            shape.setFillColor(sf::Color::Red);
            shape.setPosition(position);
            break;

        case Type::Invisibility:
            // No shape needed for invisibility
            break;
    }
}

void Pouvoir::update(float deltaTime) {
    switch (type) {
        case Type::RockThrowing:
            updateRockThrowing(deltaTime);
            break;

        case Type::Flames:
            updateFlames(deltaTime);
            break;

        case Type::Invisibility:
            updateInvisibility(deltaTime);
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

void Pouvoir::updateRockThrowing(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Pouvoir::updateFlames(float deltaTime) {
    static float timeElapsed = 0.0f;
    static float changeInterval = 0.1f; // Time in seconds to change the flame

    timeElapsed += deltaTime;

    if (timeElapsed >= changeInterval) {
        // Reset the timer
        timeElapsed = 0.0f;

        // Randomly change the size of the flame
        float newRadius = 10.0f + static_cast<float>(rand() % 5) - 2.0f; // Random radius between 8.0f and 12.0f
        shape.setRadius(newRadius);

        // Randomly change the color intensity
        int colorIntensity = 200 + rand() % 56; // Random intensity between 200 and 255
        shape.setFillColor(sf::Color(255, colorIntensity, 0)); // Red to orange color

        // Optionally, add slight movement to the flame
        float xOffset = static_cast<float>(rand() % 3) - 1.0f; // -1, 0, or 1
        float yOffset = static_cast<float>(rand() % 3) - 1.0f;
        shape.move(xOffset, yOffset);
    }
}

void Pouvoir::updateInvisibility(float deltaTime) {
    static float activeDuration = 5.0f;  // Duration the invisibility lasts
    static float cooldownDuration = 10.0f; // Cooldown duration before it can be used again
    static float timer = 0.0f;
    
    timer += deltaTime;

    if (isVisible) {
        // Invisibility is active
        if (timer > activeDuration) {
            isVisible = false;
            timer = 0.0f; // Reset timer for cooldown
        }
    } else {
        // Invisibility is on cooldown
        if (timer > cooldownDuration) {
            isVisible = true; // Invisibility is ready to be used again
            timer = 0.0f; // Reset timer for active duration
        }
    }
}


// Additional methods for rendering and collision detection can be added here
