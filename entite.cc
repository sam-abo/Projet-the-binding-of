#include "entite.hh"

//Constructeur par défaut :
Entity::Entity(){
    
};

Entity::Entity(float size, sf::Color color, float x, float y, float vitesse) {
    Objet::x = x;
    Objet::y = y;
    this -> vitesse = vitesse;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
}

Entity::Entity(float size, const sf::Color& color, float x, float y, const salle* salle) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
}

// sf::FloatRect Entity::getGlobalBounds() {
//     return forme.getGlobalBounds();
// }

void Entity::mouvement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        forme.move(-vitesse, 0.0f);
        Objet::x -= vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
        forme.move(vitesse, 0.0f);
        Objet::x += vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
        forme.move(0.0f, -vitesse);
        Objet::y -=vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
        forme.move(0.0f, vitesse);
        Objet::y += vitesse;
    }
}

// void Entity::dessiner(sf::RenderWindow& window) {
//     window.draw(forme);
// }

// void Entity::collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1 ) {
    
//     if (forme.getGlobalBounds().intersects(otherBounds)){
//         forme.setPosition(prevPositionEntity1);
//     }
// }

void Entity::deplacer(const sf::Vector2f& newPosition) {
    Objet::forme.setPosition(newPosition);
}

