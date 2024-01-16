#include "hero.hh"
#include <iostream>
#include <math.h>
#include "balles.hh"
#include "touches.hh"

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

void Hero::mouvement(Touches touche) {
sf::Vector2f nouvelle_position = this->getforme().getPosition();

    sf::Vector2f direction_mouvement_total(0.0f, 0.0f); // Initialiser le vecteur total à (0,0)

    if (touche.isKeyPressed(Left)) {
        nouvelle_position.x -= Entity::vitesse;
        direction_mouvement_total.x -= 1.0f;
    }
    if (touche.isKeyPressed(Right)) {
        nouvelle_position.x += Entity::vitesse;
        direction_mouvement_total.x += 1.0f;
    }
    if (touche.isKeyPressed(Up)) {
        nouvelle_position.y -= Entity::vitesse;
        direction_mouvement_total.y -= 1.0f;
    }
    if (touche.isKeyPressed(Down)) {
        nouvelle_position.y += Entity::vitesse;
        direction_mouvement_total.y += 1.0f;
    }

    // Normaliser le vecteur total si nécessaire
    if (direction_mouvement_total != sf::Vector2f(0.0f, 0.0f)) {
        direction_mouvement_total = direction_mouvement_total / sqrt(direction_mouvement_total.x * direction_mouvement_total.x + direction_mouvement_total.y * direction_mouvement_total.y);
    }

    direction_mouvement = direction_mouvement_total;

    this->change_pos(nouvelle_position);
};


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

float distance_entre_points(sf::Vector2f point1, sf::Vector2f point2) {
    return std::sqrt(std::pow(point2.x - point1.x, 2) + std::pow(point2.y - point1.y, 2));
};

sf::Vector2f normalize(sf::Vector2f vector) {
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0.0f) {
        return sf::Vector2f(vector.x / length, vector.y / length);
    } else {
        return vector;
    }
};

void Hero::tirer(Touches key, std::vector<Enemy>& ennemis) {
    //if (direction_mouvement == sf::Vector2f(0.0, 0.0)) {
        // Si la direction de mouvement est nulle, on trouves l'ennemi le plus proche
        // float distanceMin = 100;
        if (!ennemis.empty()) {
            // Trouver l'ennemi le plus proche
            Enemy* ennemiPlusProche = &ennemis[0];
            //if(ennemiPlusProche->getSalleAppartenance() == this->getSalleAppartenance()){
            float distanceMin = distance_entre_points(this->getforme().getPosition(), ennemiPlusProche->getforme().getPosition());
            //}
            for (Enemy& ennemi : ennemis) {
                //if(ennemi.getSalleAppartenance() == this->getSalleAppartenance()){
                float distance = distance_entre_points(this->getforme().getPosition(), ennemi.getforme().getPosition());
                if (distance < distanceMin) {
                    ennemiPlusProche = &ennemi;
                    distanceMin = distance;
                //}
                }
            }

            // Définir la direction vers l'ennemi le plus proche
            direction_mouvement = normalize(ennemiPlusProche->getforme().getPosition() - this->getforme().getPosition());
        } else {
            // Aucun ennemi trouvé, ne rien faire
            return;
        }
    //}
    if (key.isKeyPressed(key::x)) {
        if (Shootclock.getElapsedTime() > timeshoot) {
            // On crée une balle qui va se déplacer vers un ennemi
            //std::cout << "On tire" << std::endl;
            sf::Vector2f origin = this->getforme().getPosition();
            Balles projectile(origin, direction_mouvement, salleAppartenance);
            balles.push_back(projectile);
            projectile.deplacer();
            //projectile.collision_ennemi(ennemis);
            Shootclock.restart();
        }
    }
    
}