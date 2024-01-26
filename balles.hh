
#pragma once
// #include "enemy.hh"
#include "entite.hh"

class Balles : public Entity {
public:
    Balles ();
    Balles(sf::Vector2f origin, sf::Vector2f direction, textureManager& textures);
    void deplacer();

protected:
    sf::Vector2f prevPositionBalle;
    sf::Color color = sf::Color::Magenta;
    size_t size = 50.0f;
    sf::Vector2f dir;
};