#pragma once

#include <SFML/Graphics.hpp>
#include "objet.hh"

class Entity : public Objet {
public:
    Entity(float size, sf::Color color, float x, float y, float vitesse); //pour les entités mobiles
    Entity(float size, const sf::Color& color, float x, float y, const salle* salle); //pour les entités immobiles éventuellement.
    Entity();

    void mouvement(); //à mettre dans une classe mouvement
    
    void deplacer(const sf::Vector2f& newPosition);
    sf::CircleShape getforme() {return forme;};
    float& getSpeed(){return vitesse;};
    

    protected :
    float vitesse; 
};