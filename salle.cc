#include "salle.hh"



salle::salle(int width, int height, sf::Color color) {
    this->width = width;
    this->height = height;
    this->teleportPosition.x=width/2;
    this->teleportPosition.y=height/2;
    this->destination=this;
    // Création des murs
    this->wall1.setSize(sf::Vector2f(20.0f, height));
    this->wall1.setPosition(0.0f, 0.0f);
    this->wall1.setFillColor(color);
    this->wall2.setSize(sf::Vector2f(20.0f, height));
    this->wall2.setPosition(width-20.0f, 0.0f);
    this->wall2.setFillColor(color);
    this->wall3.setSize(sf::Vector2f(width, 20.0f));
    this->wall3.setPosition(0.0f, 0.0f);
    this->wall3.setFillColor(color);
    this->wall4.setSize(sf::Vector2f(width, 20.0f));
    this->wall4.setPosition(0.0f, height-20.0f);
    this->wall4.setFillColor(color);
}

void salle::dessiner(sf::RenderWindow& window){
    window.draw(wall1);
    window.draw(wall2);
    window.draw(wall3);
    window.draw(wall4);
}