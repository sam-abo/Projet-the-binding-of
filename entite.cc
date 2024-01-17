#include "entite.hh"
#include "touches.hh"

//Constructeur par défaut :
Entity::Entity(){
    
};

Entity::Entity(float size, textureManager& textures, float x, float y, float vitesse) {
    Objet::x = x;
    Objet::y = y;
    this -> vitesse = vitesse;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("marchand").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("marchand"));
    Objet::forme.setPosition(x, y);
}

Entity::Entity(float size, textureManager& textures, float x, float y, const salle* salle) {
    Objet::x = x;
    Objet::y = y;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("marchand").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("marchand"));
    Objet::forme.setPosition(x, y);
    salleAppartenance = salle;
}

// sf::FloatRect Entity::getGlobalBounds() {
//     return forme.getGlobalBounds();
// }

// void Entity::mouvement(Touches touche) {
//     if (touche.isKeyPressed(Left)) {
//         forme.move(-vitesse, 0.0f);
//         Objet::x -= vitesse;
//     }
//     if (touche.isKeyPressed(Right)) {
//         forme.move(vitesse, 0.0f);
//         Objet::x += vitesse;
//     }
//     if (touche.isKeyPressed(Up) ) {
//         forme.move(0.0f, -vitesse);
//         Objet::y -=vitesse;
//     }
//     if (touche.isKeyPressed(Down)) {
//         forme.move(0.0f, vitesse);
//         Objet::y += vitesse;
//     }
// };

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