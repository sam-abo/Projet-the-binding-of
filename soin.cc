#include "soin.hh"

// Constructors
soin::soin() {
}

soin::soin(float x, float y, const salle* salle, textureManager& textures, size_t vie)
    : Objet(x, y, salle, textures, "soin"), heal(vie) {
    getforme().setScale(5 * size / static_cast<float>(textures.getTexture("soin").getSize().x),
                       5 * size / static_cast<float>(textures.getTexture("soin").getSize().x));
}
