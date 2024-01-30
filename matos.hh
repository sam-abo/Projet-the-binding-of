#pragma once
#include "objet.hh"
#include <string>

class matos : public Objet {
public:
    matos(float x, float y, const salle* salle, textureManager& textures, std::string nom);
    
    std::string getName() const { return name; }

private:
    std::string name;
};
