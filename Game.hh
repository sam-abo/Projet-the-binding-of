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
    void game_design(Afficher& jeu, Hero& hero, sf::Vector2f prevPositionEntity1, Touches key);

    // void niveau2();
    //...
    
    private :
    // void libererMemoireCartePrecedente() {
    //     if (numCarteActive > 0) {
    //         cartes[numCarteActive - 1].libererMemoire();
    //     }
    // }

    //vecteur de cartes qui contient donc toutes les cartes du jeu qu'on va traverser.
    std::vector<carte> cartes;
    //un pointeur vers la carte active pour savoir sur quelle carte on est
    carte* carteActive;
    //cette valeur nous sers avec le pointeur de carteActive, lorsqu'on change de carte, aller cherche la nouvelle dans le vecteur des cartes
    size_t numCarteActive;

    //tout ce qui concerne la mise en place du jeu de façon graphique
    unsigned int screenWidth;
    unsigned int screenHeight;
    std::string debutJeu;
    textureManager* textures;

};