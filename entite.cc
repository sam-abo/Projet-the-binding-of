#include "entite.hh"
#include "touches.hh"

//Constructeur par défaut :
Entity::Entity(){
    
};

Entity::Entity(float size, sf::Color color, float x, float y, float vitesse) {
    Objet::x = x;
    Objet::y = y;
    this -> vitesse = vitesse;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
}

Entity::Entity(float size, const sf::Color& color, float x, float y, const salle* salle) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
}

void Entity::deplacer(const sf::Vector2f& newPosition) {
    Objet::forme.setPosition(newPosition);
};

bool Entity::bords(salle* room, sf::Vector2f prevPositionEntity1){

    if(collision(room->Getmgauche().getGlobalBounds(), prevPositionEntity1))
        return true;
    // Collision avec le bord droit
    if(collision(room->Getmdroite().getGlobalBounds(), prevPositionEntity1))
        return true;
    // Collision avec le bord haut
    if(collision(room->Getmhaut().getGlobalBounds(), prevPositionEntity1))
        return true;
    // Collision avec le bord bas
    if(collision(room->Getmbas().getGlobalBounds(), prevPositionEntity1))
        return true;
    
    return false;
};