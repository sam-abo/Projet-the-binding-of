#pragma once
#include "objet.hh"
#include "textureManager.hh"
#include "salle.hh"

class soin : public Objet {
public:
    soin(float x, float y, const salle* salle, textureManager& textures, size_t vie);
    size_t getHeal() const { return heal; }
    ~soin() {}

private:
    size_t heal;
};
