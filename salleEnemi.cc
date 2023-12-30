#include "salleEnemi.hh"

salleEnemi::salleEnemi(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas) {

    this->width = width;
    this->height = height;
    this->teleportPosition.x=width/2;
    this->teleportPosition.y=height/2;
    // Création des murs
    creermur(murgauche,0.0f,0.0f,20.0f,height,color);
    creermur(murdroite,width-20.0f,0.0f,20.0f,height,color);
    creermur(murhaut,0.0f,0.0f,width, 20.0f,color);
    creermur(murbas,0.0f, height-20.0f,width, 20.0f,color);
    creerPorte(gauchedroite,hautbas);
    
}