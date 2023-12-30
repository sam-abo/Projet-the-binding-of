#pragma once
#include "salle.hh"
#include "entite.hh"
#include <SFML/Graphics.hpp>

class salleMarchand : public salle{
    public :
    salleMarchand(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas);
    // Entity getMarchand(){return marchand;}
    private :
    sf::Texture* texture;
    // Entity marchand;
};