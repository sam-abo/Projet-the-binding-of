#include "enemy.hh"
#include "touches.hh"

//Constructeur par défaut :

Enemy::Enemy(float size, float x, float y, const salle* salle, float vitesse) {
    // Objet::x = x;
    // Objet::y = y;
    // Entity::vitesse = vitesse;
    // Objet::forme.setRadius(size);
    // Objet::forme.setFillColor(sf::Color::Red);
    // Objet::forme.setPosition(x, y);
    // salleAppartenance = salle;
    // this->hp = 150;
    Objet::x = x;
    Objet::y = y;
    Entity::vitesse = vitesse;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(sf::Color::Red);
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
    hp = 150;
}

Enemy::Enemy(float size,  float x, float y, const salle* salle) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(sf::Color::Cyan);
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
    hp = 150;
    Entity::vitesse = 0.0f;
}
