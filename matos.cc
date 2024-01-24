#include "matos.hh"

matos::matos(){};

matos:: matos (float x, float y, const salle* salle, textureManager& textures, std::string nom){
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setScale(5* size / static_cast<float>(textures.getTexture(nom).getSize().x), 5 * size / static_cast<float>(textures.getTexture(nom).getSize().x));
    Objet::forme.setTexture(textures.getTexture(nom));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
    name = nom;
};

matos:: matos (const salle* salle, textureManager& textures, std::string nom){
    Objet::forme.setScale(5* size / static_cast<float>(textures.getTexture(nom).getSize().x), 5 * size / static_cast<float>(textures.getTexture(nom).getSize().x));
    Objet::forme.setTexture(textures.getTexture(nom));
    salleAppartenance = salle;
};