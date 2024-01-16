
#pragma once
#include "enemy.hh"

class Balles : public Entity {
public:
    Balles ();
    Balles(sf::Vector2f origin, sf::Vector2f direction, const salle* room);
    void deplacer();
    void collision(salle* room, sf::Vector2f prevPositionEntity1);

    //void collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1);

protected:
    sf::Color color = sf::Color::Black;
    size_t size = 5.0f;
    sf::Vector2f dir;
};