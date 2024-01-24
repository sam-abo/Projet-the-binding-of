#pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"
#include "enemy.hh"
#include "balles.hh"
#include "soin.hh"
#include "matos.hh"

class Hero : public Entity {
public:
    /*=====================================================================================
    Faire une fonction qui fait que si le héro n'a plus d'hp, il meurt et le jeu recommence ou un truc comme ça
    =======================================================================================*/
    //contstructeur du héros
    Hero(float size, textureManager& textures, float x, float y, float vitesse);

    //getters
    int getHP(){return hp;};
    std::vector<Balles>& getBalles(){return balles;};
    std::vector<Enemy*> EnnemisDansSalle(const std::vector<Enemy>& tousLesEnnemis, salle* room);
    

    //fonction pour qu'il changes de salle
    void changersalle(salle* &salleActive, salle &newsalle, std::string direction);
    //mouvement du héros et mouvements des ennemis relativement au héros
    void mouvement(Touches touche);
    void mouv_ennemi(Enemy& entity, sf::Vector2f prevPositionEntity1);
    //collisions
    bool coll_ennemi(Enemy& foe, sf::Vector2f prevPositionEntity1);
    void collision_soin(std::vector<soin>& heal, salle* salleActive);
    void collision_items(std::vector<matos>& quete, salle* salleActive);

    
    void tirer(Touches key, std::vector<Enemy>& ennemis, textureManager& textures, salle* room);

    

    protected :
    int hp;
    std::vector<Balles> balles;
    sf::Vector2f direction_mouvement;
    sf::Clock clock;
    sf::Time time = sf::seconds(1.0f);
    sf::Clock Shootclock;
    sf::Time timeshoot = sf::seconds(0.3f);
};