#include "balles.hh"

Balles::Balles(){
};

Balles::Balles(sf::Vector2f origin, sf::Vector2f direction, textureManager& textures){
    dir = direction;
    Objet::x = origin.x;
    Objet::y = origin.y;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("bullet").getSize().x), size / static_cast<float>(textures.getTexture("bullet").getSize().x));
    Objet::forme.setTexture(textures.getTexture("bullet"));
    Objet::forme.setPosition(origin.x, origin.y);
};

void Balles::deplacer() {
    // Mettre à jour la position de la balle en fonction de sa direction
    prevPositionBalle = sf::Vector2f(this->getx(), this->gety());
    this->getx() += dir.x*3.0f;
    this->gety() += dir.y*3.0f;
    sf::Vector2f nouvellePosition = sf::Vector2f(this->getx(), this->gety());
    this->change_pos(nouvellePosition);
}

// void Balles::collision(salle* room, sf::Vector2f prevPositionBalle){
//     if(this->bords(room, prevPositionBalle)){
//         delete this;
//     }
// };

// bool Objet::collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1 ) {
    
//     if (forme.getGlobalBounds().intersects(otherBounds)){
//         forme.setPosition(prevPositionEntity1);
//         return true;
//     }
//     return false;
// };

// void Balles::collision_ennemi(std::vector<Enemy>& foes){
//      for (Enemy& mob : foes){
//         if (this->collision(mob.getGlobalBounds(), prevPositionBalle)){ //si la balle touche l'ennemi
//             //mob.getHP_ref() -= 1;
//         }
//      }
// };