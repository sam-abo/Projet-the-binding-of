#include "salle.hh"

// salle::~salle(){};
salle::salle(){};

salle::salle(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas) {

    this->width = width;
    this->height = height;
    // this->teleportPosition.x=width/2;
    // this->teleportPosition.y=height/2;
    // Création des murs
    creermur(murgauche,0.0f,0.0f,20.0f,height,color);
    creermur(murdroite,width-20.0f,0.0f,20.0f,height,color);
    creermur(murhaut,0.0f,0.0f,width, 20.0f,color);
    creermur(murbas,0.0f, height-20.0f,width, 20.0f,color);
    creerPorte(gauchedroite,hautbas);
    
}

void salle::creermur(sf::RectangleShape &wall, int startx,int starty,int width, int height, sf::Color color){
    wall.setSize(sf::Vector2f(width, height));
    wall.setPosition(startx, starty);
    wall.setFillColor(color);
}

void salle::creerPorte(std::string gauchedroite, std::string hautbas){
 if (gauchedroite=="gauche"){
        creermur(portegauche,20.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    else if (gauchedroite=="droite"){
        creermur(portedroite,width-40.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    else if (gauchedroite=="gauchedroite"){
        creermur(portegauche,20.0f,height/2-20,20.0f,40.0f,sf::Color::White);
        creermur(portedroite,width-40.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    if (hautbas=="haut"){
        creermur(portehaut,width/2-20,20,40.0f,20.0f,sf::Color::White);
    }
    else if (hautbas=="bas"){
        creermur(portebas,width/2-20,height-40,40.0f,20.0f,sf::Color::White);
    }
    else if (hautbas=="hautbas"){
        creermur(portehaut,width/2-20,20,40.0f,20.0f,sf::Color::White);
        creermur(portebas,width/2-20,height-40,40.0f,20.0f,sf::Color::White);
    }
}

void salle::print() {
    std::cout<< width << height << std::endl;
}

void salle::creersortie(){
    sortie.setSize(sf::Vector2f(50.0f, 50.0f));
    sortie.setPosition(width/2-25, height/2-25);
    sortie.setFillColor(sf::Color::Red);
}

