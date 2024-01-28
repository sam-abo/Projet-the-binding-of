#pragma once
#include "salle.hh"
#include "entite.hh"
#include <SFML/Graphics.hpp>

class salleEnemi : public salle{
    public :
    salleEnemi(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas, textureManager& textures);

    void interact() override;

    private :
    sf::Texture* texture;
};