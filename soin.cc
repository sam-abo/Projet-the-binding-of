#include "soin.hh"

soin::soin(){};

soin:: soin (float x, float y, const salle* salle, size_t vie){
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;

    heal = vie;

};