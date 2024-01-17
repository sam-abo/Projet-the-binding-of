#pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"
#include "enemy.hh"
#include "balles.hh"

class Hero : public Entity {
public:
    Hero(float size, textureManager& textures, float x, float y, float vitesse);

    int getHP(){return hp;};
    void changersalle(salle* &salleActive, salle &newsalle, std::string direction);
    void mouvement(Touches touche);
    bool coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1);
    void mouv_ennemi(Enemy& entity, sf::Vector2f prevPositionEntity1);
    // void tir(std::vector<Enemy>& enemies, Touches key);
    // void balle(Enemy* enemi, Touches key, sf::Vector2f direction);
    void tirer(Touches key, std::vector<Enemy>& ennemis, textureManager& textures);

    std::vector<Balles>& getBalles(){return balles;};

    protected :
    int hp;
    std::vector<Balles> balles;
    sf::Vector2f direction_mouvement;
    sf::Clock clock;
    sf::Time time = sf::seconds(1.0f);
    sf::Clock Shootclock;
    sf::Time timeshoot = sf::seconds(0.3f);

    //évantuellement d'autres attributs propre au héros comme son nom, sa capacité spéciale s'il en aura etc... bref
};