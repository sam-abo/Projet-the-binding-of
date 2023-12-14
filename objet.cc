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
//afficheur
void Objet::dessiner(sf::RenderWindow& window) {
    window.draw(forme);
}

//collisions
sf::FloatRect Objet::getGlobalBounds() {
    return forme.getGlobalBounds();
}

void Objet::collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1 ) {
    
    if (forme.getGlobalBounds().intersects(otherBounds)){
        forme.setPosition(prevPositionEntity1);
    }
}

