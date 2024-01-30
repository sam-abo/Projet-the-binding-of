#include "objet.hh"

// Default constructor
Objet::Objet() {}

// Parameterized constructor
Objet::Objet(float size, textureManager& textures, float x, float y, const salle* salle) {
    x = x;
    y = y;
    forme.setScale(size / static_cast<float>(textures.getTexture("marchand").getSize().x),
                   size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    forme.setTexture(textures.getTexture("marchand"));
    forme.setPosition(x, y);
    salleAppartenance = salle;
}

// Get the global bounds of the object
sf::FloatRect Objet::getGlobalBounds() {
    return forme.getGlobalBounds();
}

// Collision detection method
bool Objet::collision(const sf::FloatRect& otherBounds, sf::Vector2f prevPositionEntity1) {
    if (forme.getGlobalBounds().intersects(otherBounds)) {
        forme.setPosition(prevPositionEntity1);
        return true;
    }
    return false;
}

// Change the position of the object
void Objet::change_pos(sf::Vector2f new_pos) {
    forme.setPosition(new_pos);
}
