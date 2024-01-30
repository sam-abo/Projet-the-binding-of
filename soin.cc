#include "soin.hh"


soin::soin(float x, float y, const salle* salle, textureManager& textures, size_t vie)
    : Objet( 40.0f, textures, x, y, salle,"soin"), heal(vie) {}
