
#pragma once

#include <SFML/Graphics.hpp>
#include "salle.hh"

class Objet {
public:
    Objet();
    Objet(float size, const sf::Color& color, float x, float y, const salle* salle);
    void dessiner(sf::RenderWindow& window);

    sf::FloatRect getGlobalBounds();

    void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1);
    const salle* getSalleAppartenance() const {return salleAppartenance;}
    //forme de l'objet (toujours des cercles pour l'instant)
    sf::CircleShape getforme() {return forme;}
    int getx() {return x;}
    int gety() {return x;}

protected:
    const salle* salleAppartenance; //la salle où est l'objet
    sf::CircleShape forme; //la forme de l'objet
    float x;
    float y;
};