#pragma once

#include "salle.hh"
#include "salleMarchand.hh"
#include "hero.hh"
#include "objet.hh"

#include <SFML/Graphics.hpp>

class carte {
    
    public :
        carte(const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration,int widthsalle, int heightsalle);
        void ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string hautbas, std::string gauchedroite);
        void configurerCarte(const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration,int widthsalle, int heightsalle);
        void print();
        void deplacementEntreSalle(Hero *hero);
        void setSortie(int width, int height){grille[width-1][height-1].creersortie();}
        void setSortie(){grille[width-1][height-1].creersortie();}
        salle** getgrille() {return grille;}
        salle* getsalleActive() {return salleActive;}
        void setsalleActive(salle salle){salleActive=&salle;}
    private:
        int width;
        int height;
        salle** grille;
        salle* salleActive;
        int numsalleheight;
        int numsallewidth;
};