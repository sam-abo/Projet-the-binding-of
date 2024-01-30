#include "hero.hh"
#include <iostream>
#include <math.h>
#include "balles.hh"
#include "touches.hh"
#include "soin.hh"

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

Hero::Hero(float size, textureManager& textures, float x, float y, float vitesse){
    Objet::x = x;
    Objet::y = y;
    Entity::vitesse = vitesse;
    Objet::forme.setScale(size / static_cast<float>(textures.getTexture("nezar").getSize().x), size / static_cast<float>(textures.getTexture("marchand").getSize().x));
    Objet::forme.setTexture(textures.getTexture("nezar"));
    Objet::forme.setPosition(x, y);
    hp = 25;
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

    balles.clear();
}

bool Hero::coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1){
        if (this->getforme().getGlobalBounds().intersects(foe.getGlobalBounds())){ //si le heros touche l'ennemi
            forme.setPosition(prevPositionEntity1);
            if (clock.getElapsedTime() > time) {
            hp -= 1;
            clock.restart();
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
        //direction_mouvement_total = direction_mouvement_total / sqrt(direction_mouvement_total.x * direction_mouvement_total.x + direction_mouvement_total.y * direction_mouvement_total.y);
        direction_mouvement_total = normalize(direction_mouvement_total);
    }

    direction_mouvement = direction_mouvement_total;

    this->change_pos(nouvelle_position);
};


void Hero::mouv_ennemi(Enemy& entity, sf::Vector2f prevPositionEntity1, textureManager& textures) {
    //si et seulement si l'ennemi bouge, il va essayer de pourchasser le héro    
    // if(entity.getSpeed() != 0.0f){
    // Récupérer la position actuelle de l'entité et du héros
    sf::Vector2f positionEntity = entity.getforme().getPosition();

    // Calculer le vecteur de direction vers le héros
    sf::Vector2f direction = prevPositionEntity1 - positionEntity;

    // Normaliser le vecteur de direction (le rendre unitaire)
    direction = normalize(direction);
    // float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    // if (magnitude != 0) {
    //     direction /= magnitude;
    // }

    float vitesse = entity.getSpeed();


    // Déplacer l'ennemi vers le héros en fonction de la direction et de la vitesse

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
    //}
    //else{
        if(entity.getSpeed() == 0.0f){
        entity.tir_ennemi(textures, direction);
        return; //si l'ennemi n'est pas conçu pour bouger, rien à faire.
    }
};


std::vector<Enemy*> Hero::EnnemisDansSalle(const std::vector<Enemy>& tousLesEnnemis, salle* room) {
    std::vector<Enemy*> ennemisDansSalle;
    for (const Enemy& ennemi : tousLesEnnemis) {
        if (ennemi.getSalleAppartenance() == room) {
            ennemisDansSalle.push_back(const_cast<Enemy*>(&ennemi)); // Ajout de l'ennemi dans le vecteur
        }
    }
    return ennemisDansSalle;
}

void Hero::tirer(Touches key, std::vector<Enemy>& ennemis, textureManager& textures, salle* room) {
    sf::Vector2f direction;
    if (Shootclock.getElapsedTime() > timeshoot) {
        // Récupérer les ennemis dans la salle
        std::vector<Enemy*> ennemisDansSalle = EnnemisDansSalle(ennemis, room);

        if (!ennemisDansSalle.empty()) {
            // Trouver l'ennemi le plus proche
            Enemy* ennemiPlusProche = ennemisDansSalle[0];
            float distanceMin = distance_entre_points(this->getforme().getPosition(), ennemiPlusProche->getforme().getPosition());

            for (Enemy* ennemi : ennemisDansSalle) {
                float distance = distance_entre_points(this->getforme().getPosition(), ennemi->getforme().getPosition());
                if (distance < distanceMin) {
                    ennemiPlusProche = ennemi;
                    distanceMin = distance;
                }
            }

            // Définir la direction vers l'ennemi le plus proche
            direction = normalize(ennemiPlusProche->getforme().getPosition() - this->getforme().getPosition());
        } else {
            // Aucun ennemi dans la salle, ne rien faire
            return;
        }
         if (key.isKeyPressed(key::x)) {
            // On crée une balle qui va se déplacer vers un ennemi
            sf::Vector2f origin = this->getforme().getPosition(); //elle part de là où on est
            Balles projectile(origin, direction, textures);
            balles.push_back(projectile);
            projectile.deplacer();
            //projectile.collision_ennemi(ennemis);
            Shootclock.restart();
        }
    }

}

void Hero :: collision_soin(std::vector<soin>& heal, salle* salleActive){
    std::vector<size_t> indices_a_supprimer;

    for (size_t i = 0; i < heal.size(); ++i) {
        if (this->getforme().getGlobalBounds().intersects(heal[i].getGlobalBounds()) && ( salleActive == heal[i].getSalleAppartenance())) {
            //std::cout << "Collision détectée avec le soin à l'indice : " << i << std::endl;
            this->hp += heal[i].getHeal();
            indices_a_supprimer.push_back(i);
        }
    }

    // Supprimer les packs après la boucle
    for (auto it = indices_a_supprimer.rbegin(); it != indices_a_supprimer.rend(); ++it) {
        heal.erase(heal.begin() + *it);
    }
};


void Hero :: collision_items(std::vector<matos>& quete, salle* salleActive){
    std::vector<size_t> indices_a_supprimer;

    for (size_t i = 0; i < quete.size(); ++i) {
        if (this->getforme().getGlobalBounds().intersects(quete[i].getGlobalBounds()) && ( salleActive == quete[i].getSalleAppartenance())) {
            indices_a_supprimer.push_back(i);
            std::cout<< quete[i].getName() << " récupéré !" <<std::endl;
        }
    }

    // Supprimer les packs après la boucle
    for (auto it = indices_a_supprimer.rbegin(); it != indices_a_supprimer.rend(); ++it) {
        quete.erase(quete.begin() + *it);
    }
};

void Hero :: collision_balles(std::vector<Balles>& balles){
    std::vector<size_t> indices_a_supprimer;
    for (size_t i = 0; i < balles.size(); ++i) {
        if (this->getforme().getGlobalBounds().intersects(balles[i].getGlobalBounds())) {
            this->hp -= 1;
            indices_a_supprimer.push_back(i);
        }
    }

    // Supprimer les balles après la boucle
    for (auto it = indices_a_supprimer.rbegin(); it != indices_a_supprimer.rend(); ++it) {
        balles.erase(balles.begin() + *it);
    }
};