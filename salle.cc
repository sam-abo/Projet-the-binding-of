#include "salle.hh"
#include "entite.hh"

salle::salle(int width, int height, sf::Color color,int gauchedroite, int hautbas ) {
    this->width = width;
    this->height = height;
    this->teleportPosition.x=width/2;
    this->teleportPosition.y=height/2;
    this->destination=this;
    // Création des murs
    creermur(wall1,0.0f,0.0f,20.0f,height,color);
    creermur(wall2,width-20.0f,0.0f,20.0f,height,color);
    creermur(wall3,0.0f,0.0f,width, 20.0f,color);
    creermur(wall4,0.0f, height-20.0f,width, 20.0f,color);

    if (gauchedroite==1){
        creermur(porte1,20.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    else if (gauchedroite==2){
        creermur(porte2,width-40.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    else if (gauchedroite==3){
        creermur(porte1,20.0f,height/2-20,20.0f,40.0f,sf::Color::White);
        creermur(porte2,width-40.0f,height/2-20,20.0f,40.0f,sf::Color::White);
    }
    if (hautbas==1){
        creermur(porte3,width/2-20,20,40.0f,20.0f,sf::Color::White);
    }
    else if (hautbas==2){
        creermur(porte4,width/2-20,height-40,40.0f,20.0f,sf::Color::White);
    }
    else if (hautbas==3){
        creermur(porte3,width/2-20,20,40.0f,20.0f,sf::Color::White);
        creermur(porte4,width/2-20,height-40,40.0f,20.0f,sf::Color::White);
    }
}

void salle::dessiner(sf::RenderWindow& window){
    window.draw(wall1);
    window.draw(wall2);
    window.draw(wall3);
    window.draw(wall4);
    window.draw(porte1);
    window.draw(porte2);
    window.draw(porte3);
    window.draw(porte4);
}

void salle::creermur(sf::RectangleShape &wall, int startx,int starty,int width, int height, sf::Color color){
    wall.setSize(sf::Vector2f(width, height));
    wall.setPosition(startx, starty);
    wall.setFillColor(color);
}

