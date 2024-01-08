#include "pouvoirennemi.hh"

PouvoirEnnemi::PouvoirEnnemi(Type type, sf::Vector2f position, sf::Vector2f target)
    : Pouvoir(type, position, target) {
    switch (type) {
        case Type::Flames:
            // Initialize flames parameters
            flameRange = 100.0f; // Example value indicating the range of flames
            flameDamage = 5.0f; // Damage caused by flames per second
            break;
        case Type::SwordStriking:
            // Initialize sword striking parameters
            swordDamage = 15; // Damage caused by a sword strike
            swordReach = 50.0f; // Reach of the sword attack
            break;
        case Type::RockThrowing:
            // Initialize rock throwing parameters
            rockDamage = 10; // Damage caused by each thrown rock
            rockSpeed = 200.0f; // Speed of the thrown rock
            break;
    }
}

void PouvoirEnnemi::update(float deltaTime) {
    Pouvoir::update(deltaTime); // Call the base class update

    // Enemy-specific power updates
    switch (type) {
        case Type::Flames:
            updateFlames(deltaTime);
            break;
        case Type::SwordStriking:
            updateSwordStriking(deltaTime);
            break;
        case Type::RockThrowing:
            updateRockThrowing(deltaTime);
            break;
        // Implement other abilities updates as needed
        default:
            break;
    }
}


void PouvoirEnnemi::updateFlames(float deltaTime) {
    // Increase flame intensity or spread over time
    flameIntensity += deltaTime * flameGrowthRate; // Example growth rate

    // Check for collision with the hero or environment
    for (auto& target : targets) { // Assuming 'targets' is a list of game entities
        if (isWithinRange(target.position, flameRange)) {
            target.applyDamage(flameIntensity * deltaTime); // Apply damage over time
        }
    }

}

void PouvoirEnnemi::updateSwordStriking(float deltaTime) {
    // Check for collision with the hero
    if (isHeroInRange(hero.position, swordReach)) { // Assuming a function to check range
        if (isCollidingWithHero(hero.hitbox)) { // Assuming a function for collision detection
            hero.applyDamage(swordDamage); // Apply damage to the hero
        }
    }

}

void PouvoirEnnemi::updateRockThrowing(float deltaTime) {
    // Logic for throwing rocks
    rockThrowTimer += deltaTime;

    if (rockThrowTimer >= rockThrowCooldown) {
        rockThrowTimer = 0.0f;

        // Create a new rock and set its initial properties
        Rock newRock(rockSize, rockSpeed, position, target); // Assuming Rock constructor takes these parameters
        rocks.push_back(newRock);
    }


    for (auto& rock : rocks) {
        rock.update(deltaTime); // Assuming Rock has an update method
        if (rock.isOutOfBoundaries(gameArea)) { // Assuming a method to check if the rock is out of the game area
            rock.markForDeletion();
        }
    }

    rocks.erase(std::remove_if(rocks.begin(), rocks.end(),
                               [](const Rock& rock) { return rock.isMarkedForDeletion(); }),
                rocks.end());
}

void PouvoirEnnemi::draw(sf::RenderWindow& window) const {
    Pouvoir::draw(window); /
    
    if (type == Type::Flames) {
        // Example: Draw flames
        sf::CircleShape flameShape(flameRange);
        flameShape.setFillColor(sf::Color(255, 0, 0, 128)); // Semi-transparent red
        flameShape.setPosition(position);
        window.draw(flameShape);
    }

    if (type == Type::RockThrowing) {
        // Draw each rock
        for (const auto& rock : rocks) {
            rock.draw(window); // Assuming Rock has a draw method
        }
    }

}
