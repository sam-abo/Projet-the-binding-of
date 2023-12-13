#pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"

class Hero : public Entity {
public:
    Hero(float size, sf::Color color, float x, float y, float vitesse);
    Hero();

    protected :
    int hp;
    //évantuellement d'autres attributs propre au héros comme son nom, sa capacité spéciale s'il en aura etc... bref
};