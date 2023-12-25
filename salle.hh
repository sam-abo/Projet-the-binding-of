#pragma once
#include <SFML/Graphics.hpp>
#include "typesalle.hh"


class salle : public typesalle {
    public:
        salle();
        salle(int width, int height, sf::Color color,std::string hautbas, std::string gauchedroite);
        void dessiner(sf::RenderWindow& window);
        void creermur(sf::RectangleShape &wall, int startx,int starty, int width, int height, sf::Color color);
        void print();

        sf::RectangleShape Getmgauche () const {return murgauche;}
        sf::RectangleShape Getmdroite () const {return murdroite;}
        sf::RectangleShape Getmhaut () const {return murhaut;}
        sf::RectangleShape Getmbas () const {return murbas;}
        sf::RectangleShape Getpgauche () const {return portegauche;}
        sf::RectangleShape Getpdroite () const {return portedroite;}
        sf::RectangleShape Getphaut () const {return portehaut;}
        sf::RectangleShape Getpbas () const {return portebas;}

        sf::Vector2f& getTeleportPosition() {return teleportPosition;}
        salle* getDestination() const {return destination;}
        int getheight() {return height;}
        int getwidth() {return width;}
    private:
        int height;
        int width;
        sf::RectangleShape murgauche;
        sf::RectangleShape murdroite;
        sf::RectangleShape murhaut;
        sf::RectangleShape murbas;
        sf::RectangleShape portegauche;
        sf::RectangleShape portedroite;
        sf::RectangleShape portehaut;
        sf::RectangleShape portebas;
        sf::Vector2f teleportPosition;
        salle* destination;
};