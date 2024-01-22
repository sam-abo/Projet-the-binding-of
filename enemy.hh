 #pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"
#include "balles.hh"

class Enemy : public Entity {
public:
    Enemy(float size, float x, float y, const salle* salle, textureManager& textures); //enemi immobile
    Enemy(float size, float x, float y, const salle* salle, float vitesse, textureManager& textures); //ennemi mobile
    void collision_balles(std::vector<Balles>& balles);

    int getHP(){return hp;};

    protected :
    int hp;
    // // Enregistrement de la position precedente de l'entite 1
    // sf::Vector2f prevPositionEntity = this.getforme().getPosition();
};