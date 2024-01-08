#include "pouvoirhero.hh"


void PouvoirHero::update(float deltaTime) {
    Pouvoir::update(deltaTime); // Call the base class update

    switch (type) {
        case Type::BloodRegeneration:
            updateBloodRegeneration(deltaTime);
            break;
        case Type::Shield:
            updateShield(deltaTime);
            break;
        case Type::SwordStriking:
            updateSwordStriking(deltaTime);
            break;
        case Type::RockThrowing:
            updateRockThrowing(deltaTime);
            break;
        default:
            break;
    }
}

void PouvoirHero::updateBloodRegeneration(float deltaTime) {
    if (heroHealth < maxHeroHealth) {
        heroHealth += regenerationRate * deltaTime;
        if (heroHealth > maxHeroHealth) {
            heroHealth = maxHeroHealth;
        }
    }
}

void PouvoirHero::updateShield(float deltaTime) {
    if (shieldActive) {
        shieldTimer += deltaTime;
        if (shieldTimer > shieldDuration) {
            shieldActive = false;
            shieldTimer = 0.0f;
        }
    }
}

void PouvoirHero::updateSwordStriking(float deltaTime) {
    // Example collision detection
    for (auto& enemy : enemies) {
        if (/* sword intersects enemy */) {
            enemy->takeDamage(swordDamage);
        }
    }
}

void PouvoirHero::updateRockThrowing(float deltaTime) {
    // Handle rock throwing logic
    // Assume rocks is a list of Rock objects
    for (auto& rock : rocks) {
        rock.update(deltaTime);
        for (auto& enemy : enemies) {
            if (rock.getShape().getGlobalBounds().intersects(enemy->getHitbox())) {
                enemy->takeDamage(rockDamage);
                rock.markForDeletion();
            }
        }
    }
    rocks.erase(std::remove_if(rocks.begin(), rocks.end(),
                               [](const Rock& rock) { return rock.isMarkedForDeletion(); }),
                rocks.end());
}

void PouvoirHero::draw(sf::RenderWindow& window) const {
    Pouvoir::draw(window); // Call the base class draw

    if (type == Type::Shield && shieldActive) {
        sf::CircleShape shieldShape;
        shieldShape.setRadius(30.0f);
        shieldShape.setFillColor(sf::Color(0, 0, 255, 100));
        shieldShape.setPosition(heroPosition);
        window.draw(shieldShape);
    }
    // Additional drawing for other powers, if needed
}

