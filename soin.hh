
#pragma once
#include "objet.hh"

class soin : public Objet {
public:
    soin();
    soin(float x, float y, const salle* salle, size_t vie);
    size_t getHeal(){return heal;};
private :
    sf::Color color = sf::Color::Green;
    size_t size = 10.0f;
    size_t heal;

};