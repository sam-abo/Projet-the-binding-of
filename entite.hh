 #pragma once

#include <SFML/Graphics.hpp>
#include "objet.hh"
#include "touches.hh"
#include "salle.hh"

class Entity : public Objet {
public:
    Entity(float size, sf::Color color, float x, float y, float vitesse); //pour les entités mobiles
    Entity(float size, const sf::Color& color, float x, float y, const salle* salle); //pour les entités immobiles éventuellement.
    Entity();

    bool bords(salle* room, sf::Vector2f prevPositionEntity1);

    //void mouvement(Touches touche);
    
    
    void deplacer(const sf::Vector2f& newPosition);
    sf::CircleShape getforme() {return forme;};
    float& getSpeed(){return vitesse;};
    

    protected :
    float vitesse;
    // // Enregistrement de la position precedente de l'entite 1
    // sf::Vector2f prevPositionEntity = this.getforme().getPosition();
};