#include "hero.hh"
#include <iostream>

Hero::Hero(float size, sf::Color color, float x, float y, float vitesse){
    Objet::x = x;
    Objet::y = y;
    Entity::vitesse = vitesse;
    Objet::forme.setRadius(size);
    Objet::forme.setFillColor(color);
    Objet::forme.setPosition(x, y);
    hp = 100;
};

void Hero::changersalle( salle* &salleActive, salle &newsalle, std::string direction){
    if (direction=="gauche"){
        if (getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f(newsalle.getwidth()-200,(newsalle.getheight())/2));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="droite"){
        if (getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f(100,(newsalle.getheight())/2));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="haut"){
        if (getGlobalBounds().intersects(salleActive->Getphaut().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f((newsalle.getwidth())/2,(newsalle.getheight())-200));
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
    if (direction=="bas"){
        if (getGlobalBounds().intersects(salleActive->Getpbas().getGlobalBounds()) && &newsalle!= salleActive) {
                // Teleportez l'entite à la position specifiee dans la deuxième salle
                deplacer(sf::Vector2f((newsalle.getwidth())/2,100));
                std::cout<<"ah"<<std::endl;
                // Changez la salle active
                salleActive=&newsalle;
            }
    }
}

void Hero::coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1){
    
        if (this->getforme().getGlobalBounds().intersects(foe.getGlobalBounds())){ //si le heros touche l'ennemi
            forme.setPosition(prevPositionEntity1);
            if (clock.getElapsedTime() > time) {
            hp -= 1;
            clock.restart(); //en fait c'est le temps écoulé depuis le dernier restart
            }
        }
};

//idéalement faudrait réussir à ne mettre les mouvements que ici

// void Hero::mouvement(Touches touche) {
//     if (touche.isKeyPressed(Left)) {
//         this->getforme().move(-Entity::vitesse, 0.0f);
//         Objet::x -= Entity::vitesse;
//     }
//     if (touche.isKeyPressed(Right)) {
//         this->getforme().move(Entity::vitesse, 0.0f);
//         Objet::x += Entity::vitesse;
//     }
//     if (touche.isKeyPressed(Up) ) {
//         this->getforme().move(0.0f, -Entity::vitesse);
//         Objet::y -=Entity::vitesse;
//     }
//     if (touche.isKeyPressed(Down)) {
//         this->getforme().move(0.0f, Entity::vitesse);
//         Objet::y += Entity::vitesse;
//     }
// };
