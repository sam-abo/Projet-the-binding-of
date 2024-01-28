#include "salleEnemi.hh"

salleEnemi::salleEnemi(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas, textureManager& textures) {

    this->width = width;
    this->height = height;
    // Création des murs
    creermur(murgauche,0.0f,0.0f,20.0f,height,color);
    creermur(murdroite,width-20.0f,0.0f,20.0f,height,color);
    creermur(murhaut,0.0f,0.0f,width, 20.0f,color);
    creermur(murbas,0.0f, height-20.0f,width, 20.0f,color);
    creerPorte(gauchedroite,hautbas);
    
    type="salleEnemi";

    salle::fond.setTexture(textures.getTexture("fond"));
    salle::fond.setScale(width / static_cast<float>(textures.getTexture("fond").getSize().x), height / static_cast<float>(textures.getTexture("fond").getSize().y));
    salle::fond.setPosition(0.0f,0.0f);
}

void salleEnemi::interact() {
    // Implementation of interaction in an enemy room
    // For instance, triggering a battle
    std::cout << "Preparing for battle with enemies" << std::endl;
}