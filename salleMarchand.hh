#pragma once
#include "salle.hh"
#include "entite.hh"
#include <SFML/Graphics.hpp>

class salleMarchand : public salle{
    public :
    salleMarchand(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas, textureManager& textures);
    // Entity getMarchand(){return marchand;}
    private :
    // sf::Sprite marchand;
    // Entity marchand;
};