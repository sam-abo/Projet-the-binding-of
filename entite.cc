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

// sf::FloatRect Entity::getGlobalBounds() {
//     return forme.getGlobalBounds();
// }

void Entity::mouvement(Touches touche) {
    if (touche.isKeyPressed(Left)) {
        forme.move(-vitesse, 0.0f);
        Objet::x -= vitesse;
    }
    if (touche.isKeyPressed(Right)) {
        forme.move(vitesse, 0.0f);
        Objet::x += vitesse;
    }
    if (touche.isKeyPressed(Up) ) {
        forme.move(0.0f, -vitesse);
        Objet::y -=vitesse;
    }
    if (touche.isKeyPressed(Down)) {
        forme.move(0.0f, vitesse);
        Objet::y += vitesse;
    }
};

void Entity::deplacer(const sf::Vector2f& newPosition) {
    Objet::forme.setPosition(newPosition);
};

void Entity::bords(salle* room, sf::Vector2f prevPositionEntity1){

    collision(room->Getmgauche().getGlobalBounds(), prevPositionEntity1);
    // Collision avec le bord droit
    collision(room->Getmdroite().getGlobalBounds(), prevPositionEntity1);
    // Collision avec le bord haut
    collision(room->Getmhaut().getGlobalBounds(), prevPositionEntity1);
    // Collision avec le bord bas
    collision(room->Getmbas().getGlobalBounds(), prevPositionEntity1);
};