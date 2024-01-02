#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity;

class salle {
    public:
        salle();
        salle(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas);
        //void dessiner(sf::RenderWindow& window);
        void creermur(sf::RectangleShape &wall, int startx,int starty, int width, int height, sf::Color color);
        void creerPorte(std::string gauchedroite, std::string hautbas);
        void print();
        void creersortie();

        sf::RectangleShape Getmgauche () const {return murgauche;}
        sf::RectangleShape Getmdroite () const {return murdroite;}
        sf::RectangleShape Getmhaut () const {return murhaut;}
        sf::RectangleShape Getmbas () const {return murbas;}
        sf::RectangleShape Getpgauche () const {return portegauche;}
        sf::RectangleShape Getpdroite () const {return portedroite;}
        sf::RectangleShape Getphaut () const {return portehaut;}
        sf::RectangleShape Getpbas () const {return portebas;}
        sf::RectangleShape Getsortie () const {return sortie;}
        Entity* Getmarchand() {return marchand;}

        sf::Vector2f& getTeleportPosition() {return teleportPosition;}
        
        int getheight() {return height;}
        int getwidth() {return width;}
    protected:
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
        sf::RectangleShape sortie;
        Entity* marchand;
        sf::Vector2f teleportPosition;
};