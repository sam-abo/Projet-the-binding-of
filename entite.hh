#pragma once

#include <SFML/Graphics.hpp>
#include "salle.hh"

class Entity {
public:
    Entity(float size, sf::Color color, float x, float y, float vitesse);
    Entity(float size, const sf::Color& color, float x, float y, const salle* salle);

    void mouvement();
    void dessiner(sf::RenderWindow& window);
    void changersalle(salle* &salleActive, salle &newsalle, std::string direction);

    sf::FloatRect getGlobalBounds();
    void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1);
    void deplacer(const sf::Vector2f& newPosition);
    const salle* getSalleAppartenance() const {return salleAppartenance;}
    sf::CircleShape getforme() {return forme;}
    int getx() {return x;}
    int gety() {return x;}

private:
    const salle* salleAppartenance;
    sf::CircleShape forme;
    float x;
    float y;
    float vitesse;
};