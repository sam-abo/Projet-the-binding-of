
#pragma once

#include <SFML/Graphics.hpp>
#include "salle.hh"
#include <iostream>

class Objet {
public:
    Objet();
    Objet(float size, textureManager& textures, float x, float y, const salle* salle);

    sf::FloatRect getGlobalBounds(); // intervient dans la collision

    bool collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1);
    const salle* getSalleAppartenance() const {return salleAppartenance;}
    //forme de l'objet (toujours des cercles pour l'instant)
    sf::Sprite getforme() {return forme;}
    float& getx() {return x;}
    float& gety() {return y;}
    void change_pos(sf::Vector2f new_pos);

protected:
    const salle* salleAppartenance; //la salle où est l'objet
    sf::Sprite forme; //la forme de l'objet
    float x;
    float y;
};