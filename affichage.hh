#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "hero.hh"

class Afficher {
    public:
        void afficherHP(Hero& hero); //à mettre dans une classe affchage (hero)
        void dessiner_obj(Objet& objet); //à mettre dans une classe affchage (objet)
        void dessiner_salle(salle* s); //ne dessine que la salle active
        
        //sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "The binding of chatelêt les halles"); //dans la classe affichage (la fenêtre deu jeu)
        void Fenetre_jeu(std::string nom);
        sf::RenderWindow& getWindow(){return window;};
    private:
    sf::RenderWindow window;
};