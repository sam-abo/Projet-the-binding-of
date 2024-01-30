#include "enemy.hh"
#include "touches.hh"

//Constructeur par défaut :

Enemy::Enemy(float size, float x, float y, const salle* salle, float vitesse, textureManager& textures) {

    Objet::x = x;
    Objet::y = y;
    Entity::vitesse = vitesse;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("crackhead").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("crackhead"));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
    hp = 35;
}

Enemy::Enemy(float size,  float x, float y, const salle* salle, textureManager& textures) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("crackhead").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("crackhead"));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
    hp = 15;
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

void Enemy :: tir_ennemi(textureManager& textures, sf::Vector2f direction){
    if(Shootclock.getElapsedTime() > timeshoot){
    sf::Vector2f origin = this->getforme().getPosition(); //elle part de là où on est
    Balles projectile(origin, direction, textures);
    balles.push_back(projectile);
    projectile.deplacer();
    //projectile.collision_ennemi(ennemis);
    Shootclock.restart();
    }
};