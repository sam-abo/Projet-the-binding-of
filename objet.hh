
#pragma once

#include <SFML/Graphics.hpp>
#include "salle.hh"
#include <iostream>

class Objet {
public:
    Objet();
    Objet(float size, const sf::Color& color, float x, float y, const salle* salle);

    sf::FloatRect getGlobalBounds(); // intervient dans la collision

    void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1); //à mettre dans la classe mouvement
    const salle* getSalleAppartenance() const {return salleAppartenance;}
    //forme de l'objet (toujours des cercles pour l'instant)
    sf::CircleShape getforme() {return forme;}
    float& getx() {return x;}
    float& gety() {return y;}

protected:
    const salle* salleAppartenance; //la salle où est l'objet
    sf::CircleShape forme; //la forme de l'objet
    float x;
    float y;
};