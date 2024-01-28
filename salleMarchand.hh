#pragma once
#include "salle.hh"
#include "entite.hh"
#include <SFML/Graphics.hpp>

class salleMarchand : public salle{
    public :
    salleMarchand(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas, textureManager& textures);

    sf::Vector2f getMerchantPosition();
    
    void interact() override;

    void talkToMerchant();  // Declaration of the method
    // Entity getMarchand(){return marchand;}
    private :
    bool hastalkedtomerchant = false;
    // sf::Sprite marchand;
    // Entity marchand;
};