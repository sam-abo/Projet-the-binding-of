#pragma once

#include "salle.hh"
#include "salleMarchand.hh"
#include "salleEnemi.hh"
#include "hero.hh"
#include "soin.hh"
#include "matos.hh"

#include <SFML/Graphics.hpp>

class carte {
    
    public :
        //désalloueur de mémoire de carte pour gérer la mémoire plus facilement :
        void libererMemoire();

        //constructeur de carte
        carte(int widthsalle, int heightsalle, textureManager& textures);
        //const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration
        //intervient dans la création de carte
        void configurerCarte(const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration,int widthsalle, int heightsalle, textureManager& textures);
        //foncions d'initialisation pour les cartes
        void Init(size_t i, textureManager& textures);
        void Init0(textureManager& textures);
        void Init1(textureManager& textures);
        // void Init2(textureManager& textures);
        // void Init3(textureManager& textures);
        // void Init4(textureManager& textures);
        // void Init5(textureManager& textures);
        // void Init6(textureManager& textures);
        
        //ajout de salle (a priori pas besoin)
        // void ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string hautbas, std::string gauchedroite);
        
        //void print(); //a changer en opérateur pour tests unitaires ? à la base devait simplement servir à afficher la dimension des salles d'une carte.

        //gère le déplacement du héros
        void deplacementEntreSalle(Hero &hero);

        //SETTERS
        //gère les sorties
        void setSortie(int w, int h){grille[w-1][h-1].creersortie();} //avec cette version de la méthode, on créé une sortie à l'endroit spécifié
        void setSortie(){grille[width-1][height-1].creersortie();} // avec cette version de la méthode, on créé une sortie à la dernière salle, celle en bas à droite
        //gère la salle active
        void setsalleActive(salle salle){salleActive=&salle;} //initialise la salle active comme étant la sale passée en paramètre
        //GETTERS
        salle** getgrille() {return grille;}
        salle* getsalleActive() {return salleActive;}
        std::vector<Entity>& getEntities() { return entities; }
        std::vector<Enemy>& getFoes() { return foes; }
        std::vector<soin>& getPackSoin() { return pack_soin; }
        std::vector<matos>& getmatos() { return items; }
        

    private:
        //dimensions de la carte, elles feront toutes 3x3
        size_t width; //= 3;
        size_t height; //=3;
        salle** grille; //une grille de salle pour la carte courante qui aura donc les dimensions width et height
        salle* salleActive;
        int numsalleheight;
        int numsallewidth;
        //fameuse matrice des portes, plus rapide de la déclarer là. configuration
        std::vector<std::vector<std::pair<std::string, std::string>>> configuration = {
        {{"bas", "droite"},{"bas", "gauchedroite"}, {"bas", "gauche"}},
        {{"hautbas", "droite"},{"hautbas", "gauchedroite"}, {"hautbas", "gauche"}},
        {{"haut", "droite"},{"haut", "gauchedroite"}, {"haut", "gauche"}}
        };

        //vecteurs de tout ce qu'il y a dans la map, à savoir ennemis, entités et soins.
        std::vector<soin> pack_soin;
        std::vector<Enemy> foes;
        std::vector<Entity> entities;
        std::vector<matos> items;
        //potentiellement important, un vecteur d'objets qui seront donc des bonus et autres trucs à collecter.
};