#include "matos.hh"

// Constructors
matos::matos() {
}

matos::matos(float x, float y, const salle* salle, textureManager& textures, std::string nom)
    : Objet(x, y, salle, textures, nom), name(nom) {
    getforme().setScale(5 * size / static_cast<float>(textures.getTexture(nom).getSize().x),
                       5 * size / static_cast<float>(textures.getTexture(nom).getSize().x));
}

matos::matos(const salle* salle, textureManager& textures, std::string nom)
    : Objet(salle, textures, nom), name(nom) {
    getforme().setScale(5 * size / static_cast<float>(textures.getTexture(nom).getSize().x),
                       5 * size / static_cast<float>(textures.getTexture(nom).getSize().x));
}
