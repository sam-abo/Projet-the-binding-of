#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "hero.hh"
#include "enemy.hh"
#include "salle.hh"
#include "touches.hh"
#include "soin.hh"
#include "menu.hh"

class Afficher {
    public:
        void afficherHP(Hero& hero);
        void dessiner_balles(std::vector<Balles>& balles);
        void afficherHP(Enemy& foe);
        void afficher_heal(soin& pack);

        void afficher_quete(Entity& pnj);

        void dessiner_obj(Objet& objet);
        void dessiner_salle(salle* s); //ne dessine que la salle active
        std::string dessiner_menu(Menu& m, sf::Event& event);
        
        void Fenetre_jeu(std::string nom);
        void fermeture (Touches touche);
        sf::RenderWindow& getWindow(){return window;};
    private:
    sf::RenderWindow window;
};