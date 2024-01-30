#include "matos.hh"

matos::matos(float x, float y, const salle* salle, textureManager& textures, std::string nom)
    : Objet(40.0f, textures, x, y, salle,nom), name(nom) {}
