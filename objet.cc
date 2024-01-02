#include "objet.hh"

//Constructeur par défaut :
Objet::Objet(){  
};

Objet::Objet(float size, const sf::Color& color, float x, float y, const salle* salle) {
    x = x;
    y = y;
    forme.setRadius(size);
    forme.setFillColor(color);
    forme.setPosition(x, y);
    salleAppartenance = salle;
};


//collisions
sf::FloatRect Objet::getGlobalBounds() {
    return forme.getGlobalBounds();
}

void Objet::collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1 ) {
    
    if (forme.getGlobalBounds().intersects(otherBounds)){
        forme.setPosition(prevPositionEntity1);
    }
};

void Objet::change_pos(sf::Vector2f new_pos){
    forme.setPosition(new_pos);
}