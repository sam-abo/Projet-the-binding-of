#pragma once

#include "objet.hh"

class matos : public Objet {
public:
    // Constructors
    matos();
    matos(float x, float y, const salle* salle, textureManager& textures, std::string nom);
    matos(const salle* salle, textureManager& textures, std::string nom);

    // Getter
    std::string getName() const { return name; }

private:
    // Attributes
    std::string name;
    static constexpr size_t size = 10.0f; // Adjust as needed
};

#include "matos.cc"  // Include the corresponding implementation file
