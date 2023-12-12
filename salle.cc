#include "salle.hh"



salle::salle(int width, int height, sf::Color color ) {
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
}

void salle::dessiner(sf::RenderWindow& window){
    window.draw(wall1);
    window.draw(wall2);
    window.draw(wall3);
    window.draw(wall4);
}

void salle::creermur(sf::RectangleShape &wall, int startx,int starty,int widht, int height, sf::Color color){
    wall.setSize(sf::Vector2f(widht, height));
    wall.setPosition(startx, starty);
    wall.setFillColor(color);
}