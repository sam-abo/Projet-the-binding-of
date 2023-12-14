#pragma once

#include <SFML/Graphics.hpp>

#include "salle.hh"
//#include "carte.hh"
#include "objet.hh"


class Entity : public Objet {
public:
    Entity(float size, sf::Color color, float x, float y, float vitesse); //pour les entités mobiles
    Entity(float size, const sf::Color& color, float x, float y, const salle* salle); //pour les entités immobiles éventuellement.
    Entity();

    void mouvement();
    //void dessiner(sf::RenderWindow& window);


    //sf::FloatRect getGlobalBounds();
    //void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1);
    void deplacer(const sf::Vector2f& newPosition);
    //const salle* getSalleAppartenance() const {return salleAppartenance;}
    sf::CircleShape getforme() {return forme;}
    //int getx() {return Objet::x;}
    //int gety() {return Objet::x;}

    protected :
    float vitesse; 
};