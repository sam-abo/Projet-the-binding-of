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
}

// sf::FloatRect Enemy::getGlobalBounds() {
//     return forme.getGlobalBounds();
// }

// void Enemy::mouvement(Touches touche) {
//     if (touche.isKeyPressed(Left)) {
//         forme.move(-vitesse, 0.0f);
//         Objet::x -= vitesse;
//     }
//     if (touche.isKeyPressed(Right)) {
//         forme.move(vitesse, 0.0f);
//         Objet::x += vitesse;
//     }
//     if (touche.isKeyPressed(Up) ) {
//         forme.move(0.0f, -vitesse);
//         Objet::y -=vitesse;
//     }
//     if (touche.isKeyPressed(Down)) {
//         forme.move(0.0f, vitesse);
//         Objet::y += vitesse;
//     }
// };

