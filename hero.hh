#pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"
#include "enemy.hh"

class Hero : public Entity {
public:
    Hero(float size, sf::Color color, float x, float y, float vitesse);

    int getHP(){return hp;};
    void changersalle(salle* &salleActive, salle &newsalle, std::string direction);
    // void mouvement(Touches touche);
    void coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1);

    protected :
    int hp;
    std::vector<Objet> inventaire;
    sf::Clock clock;
    sf::Time time = sf::seconds(1.0f);

    //évantuellement d'autres attributs propre au héros comme son nom, sa capacité spéciale s'il en aura etc... bref
};