#pragma once
#include <SFML/Graphics.hpp>
#include "hero.hh"
#include "touches.hh"
class Mouvement {
    void mouvement(Entity& entite); //à mettre dans une classe mouvement (entité)
    void mouvement_hero(Hero& Hero,Touches touche); //à mettre dans une classe mouvement (héro)
    void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity); //à mettre dans la classe mouvement (Collision entre objets)
    sf::FloatRect getGlobalBounds(); // intervient dans la collision
};