#pragma once
#include <SFML/Graphics.hpp>
#include "affichage.hh"
#include "touches.hh"
#include "hero.hh"
#include "enemy.hh"
#include "salle.hh"
#include "carte.hh"
#include "menu.hh"
#include "textureManager.hh"

class Game {
    public :
    Game(int i);
    void jouer();

    void niveau();
    
    private :
    carte* carteActive;
    std::vector<carte> cartes;
    int numCarteActive;
    unsigned int screenWidth;
    unsigned int screenHeight;
    std::string debutJeu;
    textureManager* textures;

};