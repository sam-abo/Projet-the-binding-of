#include "entite.hh"


Entity::Entity(float size, sf::Color color, float x, float y, float vitesse) : x(x),y(y),vitesse(vitesse){
    forme.setRadius(size);
    forme.setFillColor(color);
    forme.setPosition(x, y);
}

Entity::Entity(float size, const sf::Color& color, float x, float y, const salle* salle) : x(x),y(y) {
    forme.setRadius(size);
    forme.setFillColor(color);
    forme.setPosition(x, y);
    salleAppartenance=salle;
}

sf::FloatRect Entity::getGlobalBounds() {
    return forme.getGlobalBounds();
}

void Entity::mouvement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        forme.move(-vitesse, 0.0f);
        x-=vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
        forme.move(vitesse, 0.0f);
        x+=vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
        forme.move(0.0f, -vitesse);
        y-=vitesse;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
        forme.move(0.0f, vitesse);
        y+=vitesse;
    }
}

void Entity::dessiner(sf::RenderWindow& window) {
    window.draw(forme);
}

void Entity::collision(const sf::FloatRect& otherBounds,sf::Vector2f prevPositionEntity1 ) {
    
    if (forme.getGlobalBounds().intersects(otherBounds)){
        forme.setPosition(prevPositionEntity1);
    }
}

void Entity::deplacer(const sf::Vector2f& newPosition) {
    forme.setPosition(newPosition);
}

void Entity::changersalle( salle* &salleActive, salle &newsalle, std::string direction){
    if (direction=="gauche"){
        if (getGlobalBounds().intersects(salleActive->Getp1().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f(newsalle.getwidth()-200,(newsalle.getheight())/2));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="droite"){
        if (getGlobalBounds().intersects(salleActive->Getp2().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f(100,(newsalle.getheight())/2));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="haut"){
        if (getGlobalBounds().intersects(salleActive->Getp3().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f((newsalle.getwidth())/2,(newsalle.getheight())-200));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="bas"){
        if (getGlobalBounds().intersects(salleActive->Getp4().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f((newsalle.getwidth())/2,100));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
}