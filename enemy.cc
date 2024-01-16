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

void Enemy :: collision_balles(std::vector<Balles>& balles){
    std::vector<size_t> indices_a_supprimer;
    for (size_t i = 0; i < balles.size(); ++i) {
        if (this->getforme().getGlobalBounds().intersects(balles[i].getGlobalBounds())) {
            this->hp -= 1;
            indices_a_supprimer.push_back(i);
        }
    }

    // Supprimer les balles après la boucle
    for (auto it = indices_a_supprimer.rbegin(); it != indices_a_supprimer.rend(); ++it) {
        balles.erase(balles.begin() + *it);
    }
};