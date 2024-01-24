 #pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"
#include "balles.hh"

class Enemy : public Entity {
public:
    /*===========================================================
    ajouter plus de sprites d'ennemis comme des sprites de policier et faire un truc qui choisis au hasard quel sprite entre les 2 ou plus aura l'ennemi en question

    - les ennemis n'ont pas trop besoin de hp ducoup, pour la difficulté du jeu on peut dire qu'ils sont intuables.

    ===============================================================
    */
    Enemy(float size, float x, float y, const salle* salle, textureManager& textures); //enemi immobile
    Enemy(float size, float x, float y, const salle* salle, float vitesse, textureManager& textures); //ennemi mobile
    void collision_balles(std::vector<Balles>& balles); //modifier cette fonction pour que les ennemis soient par exemple ralentis pendant un certain temps.

    //==================================== il faut ajouter un tir d'ennemi pour les ennemis qui bougent pas, tirs qui ralentissent le héros

    int getHP(){return hp;};

    protected :
    int hp;
    //prévoir un sf::clock pour le ralentissement et les tirs, exemple dans hero.hh et .cc
};