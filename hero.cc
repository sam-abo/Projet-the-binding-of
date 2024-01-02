#include "hero.hh"
#include <iostream>
#include <math.h>

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

bool Hero::coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1){
        if (this->getforme().getGlobalBounds().intersects(foe.getGlobalBounds())){ //si le heros touche l'ennemi
            forme.setPosition(prevPositionEntity1);
            if (clock.getElapsedTime() > time) {
            hp -= 1;
            clock.restart(); //en fait c'est le temps écoulé depuis le dernier restart
            }
        return true;
        }
    return false;
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


void Hero::mouv_ennemi(Enemy& entity, sf::Vector2f prevPositionEntity1) {
    // Récupérer la position actuelle de l'entité et du héros
    sf::Vector2f positionEntity = entity.getforme().getPosition();

    // Calculer le vecteur de direction vers le héros
    sf::Vector2f direction = prevPositionEntity1 - positionEntity;

    // Normaliser le vecteur de direction (le rendre unitaire)
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction /= magnitude;
    }

    float vitesse = entity.getSpeed();


    // Déplacer l'entité vers le héros en fonction de la direction et de la vitesse

    coll_ennemi(entity, prevPositionEntity1);

    if (coll_ennemi(entity, prevPositionEntity1)) {
        return;
    } else {
        // Sinon, mettre à jour la position
        entity.getx() += direction.x * vitesse;
        entity.gety() += direction.y * vitesse;
        sf::Vector2f nouvellePosition = sf::Vector2f(entity.getx(), entity.gety());
        entity.change_pos(nouvellePosition);
    }
}
