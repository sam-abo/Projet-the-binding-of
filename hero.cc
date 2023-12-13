#include "hero.hh"

Hero::Hero(float size, sf::Color color, float x, float y, float vitesse){
    Objet::x = x;
    Objet::y = y;
    Entity::vitesse = vitesse;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
    hp = 100;
};

Hero::Hero(){

};

void Hero::changersalle( salle* &salleActive, salle &newsalle, std::string direction){
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

//  void Hero::afficherHP(sf::RenderWindow& window){
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf")) {
//     // Gestion de l'erreur si la police ne peut pas être chargée
//     return;
//     }
    
//     hpText.setFont(font);
//     hpText.setCharacterSize(24);
//     hpText.setFillColor(sf::Color::Green);
//     hpText.setString("HP: " + std::to_string(getHP()));
//  };