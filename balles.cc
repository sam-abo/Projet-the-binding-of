#include "balles.hh"

Balles::Balles(){
};

Balles::Balles(sf::Vector2f origin, sf::Vector2f direction, const salle* room){
    dir = direction;
    Objet::x = origin.x;
    Objet::y = origin.y;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(origin.x, origin.y);
    salleAppartenance = room;
};

void Balles::deplacer() {
    // Mettre à jour la position de la balle en fonction de sa direction
    this->getx() += dir.x*3.0f;
    this->gety() += dir.y*3.0f;
    sf::Vector2f nouvellePosition = sf::Vector2f(this->getx(), this->gety());
    this->change_pos(nouvellePosition);
}

void Balles::collision(salle* room, sf::Vector2f prevPositionBalle){
    if(this->bords(room, prevPositionBalle)){
        delete this;
    }
};