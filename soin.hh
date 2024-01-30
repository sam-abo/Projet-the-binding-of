#pragma once

#include "objet.hh"

class soin : public Objet {
public:
    // Constructors
    soin();
    soin(float x, float y, const salle* salle, textureManager& textures, size_t vie);

    // Getter
    size_t getHeal() const { return heal; }

private:
    // Attributes
    static constexpr sf::Color color = sf::Color::Green;
    static constexpr size_t size = 10.0f; // Adjust as needed
    size_t heal;
};

#include "soin.cc"  // Include the corresponding implementation file
