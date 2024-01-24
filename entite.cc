#include "entite.hh"
#include "touches.hh"

//Constructeur par défaut :
Entity::Entity(){
    
};

// void Entity::pnj(float size, textureManager& textures, float x, float y, const salle* salle) { //constructeur un peu inutile, on l'utilise jamais.
//     Objet::x = x;
//     Objet::y = y;
//     Objet::forme.setScale(size / static_cast<float>(textures.getTexture("marchand").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
//     Objet::forme.setTexture(textures.getTexture("marchand"));
//     Objet::forme.setPosition(x, y);
//     salleAppartenance = salle;
// }

Entity::Entity(float size, textureManager& textures, float x, float y, const salle* salle) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("marchand").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("marchand"));
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