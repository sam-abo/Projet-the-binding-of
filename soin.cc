#include "soin.hh"


soin::soin(){};

soin:: soin (float x, float y, const salle* salle, textureManager& textures, size_t vie){
    Objet::x = x;
    Objet::y = y;
    // Objet::forme.setRadius(size);
    // Objet::forme.setFillColor(color);
    Objet::forme.setScale(5* size / static_cast<float>(textures.getTexture("soin").getSize().x), 5 * size / static_cast<float>(textures.getTexture("soin").getSize().x));
    Objet::forme.setTexture(textures.getTexture("soin"));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;

    heal = vie;

};