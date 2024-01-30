#pragma once

#include <SFML/Graphics.hpp>
#include "salle.hh"
#include "textureManager.hh" // Assuming you have a textureManager class

class Objet {
public:
    Objet();
    Objet(float size, textureManager& textures, float x, float y, const salle* salle, std::string nom);

    virtual sf::FloatRect getGlobalBounds(); // Intervenes in collision

    virtual bool collision(const sf::FloatRect& otherBounds, sf::Vector2f prevPositionEntity1);
    const salle* getSalleAppartenance() const { return salleAppartenance; }
    sf::Sprite getforme() { return forme; }
    float& getx() { return x; }
    float& gety() { return y; }
    void change_pos(sf::Vector2f new_pos);

protected:
    const salle* salleAppartenance; // The room where the object is
    sf::Sprite forme;               // The shape of the object
    float x;
    float y;
};
