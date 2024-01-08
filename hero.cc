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
};

void Hero:: tir(std::vector<Enemy>& enemies) {
        // Vérifier s'il y a des ennemis
        if (enemies.empty()) {
            return; // Aucun ennemi à tirer
        }

        // Initialiser des variables pour suivre l'ennemi le plus proche
        Enemy* ennemiPlusProche = nullptr;
        float distanceMin = std::numeric_limits<float>::max();

        // Récupérer la position du héros
        sf::Vector2f positionHero = this->getforme().getPosition();

        // Parcourir tous les ennemis pour trouver le plus proche
        for (Enemy& ennemi : enemies) {
            // Récupérer la position de l'ennemi
            sf::Vector2f positionEnnemi = ennemi.getforme().getPosition();

            // Calculer la distance entre le héros et l'ennemi
            float distance = std::sqrt(std::pow(positionEnnemi.x - positionHero.x, 2) +
                                        std::pow(positionEnnemi.y - positionHero.y, 2));

            // Mettre à jour l'ennemi le plus proche si nécessaire
            if (distance < distanceMin) {
                distanceMin = distance;
                ennemiPlusProche = &ennemi;
            }
        }

        // Si un ennemi a été trouvé, tirer un projectile
        if (ennemiPlusProche != nullptr) {
            // Ajoutez ici le code pour créer et tirer un projectile
            // Vous pouvez, par exemple, créer une instance de la classe Projectile
            // et l'ajouter à une liste de projectiles dans votre jeu.
            // Assurez-vous que la classe Projectile est correctement définie.

            // Exemple imaginaire :
            // Projectile projectile(positionHero, ennemiPlusProche->getforme().getPosition());
            // listeProjectiles.push_back(projectile);
        }
    }
