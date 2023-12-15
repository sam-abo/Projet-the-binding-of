#pragma once
#include "salle.hh"

#include <SFML/Graphics.hpp>

class carte {
    public :
        carte(const std::vector<std::vector<int>>& configuration,int widthsalle, int heightsalle);
        void ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string hautbas, std::string gauchedroite);
        void configurerCarte(const std::vector<std::vector<int>>& configuration,int widthsalle, int heightsalle);
    private:
        int width;
        int height;
        std::vector<std::vector<salle>> grille;
};