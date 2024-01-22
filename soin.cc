#include "soin.hh"


soin::soin(){};

soin:: soin (float x, float y, const salle* salle, textureManager& textures, size_t vie){
    Objet::x = x;
    Objet::y = y;
    // Objet::forme.setRadius(size);
    // Objet::forme.setFillColor(color);
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("bullet").getSize().x), size / static_cast<float>(textures.getTexture("bullet").getSize().x));
    Objet::forme.setTexture(textures.getTexture("bullet"));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;

    heal = vie;

};