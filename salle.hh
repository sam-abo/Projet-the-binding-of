#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "textureManager.hh"
//#include "enemy.hh"

class Enemy;

class salle {
    public:
        //constructeurs de salle
        salle();//constructeur par défaut pour assurer l'existence des classes filles.
        salle(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas);
        
        void creermur(sf::RectangleShape &wall, int startx,int starty, int width, int height, sf::Color color);
        void creerPorte(std::string gauchedroite, std::string hautbas);
        void print();
        
        //créer une sortie, permet d'avoir une sortie conditionnée
        void creersortie();

        //getters nécessaires, murs portes et sorties
        sf::RectangleShape Getmgauche () const {return murgauche;}
        sf::RectangleShape Getmdroite () const {return murdroite;}
        sf::RectangleShape Getmhaut () const {return murhaut;}
        sf::RectangleShape Getmbas () const {return murbas;}
        sf::RectangleShape Getpgauche () const {return portegauche;}
        sf::RectangleShape Getpdroite () const {return portedroite;}
        sf::RectangleShape Getphaut () const {return portehaut;}
        sf::RectangleShape Getpbas () const {return portebas;}
        sf::RectangleShape Getsortie () const {return sortie;}
        sf::Sprite Getmarchand() {return marchand;}
        sf::Sprite Getfond() {return fond;}
        std::string Gettype(){return type;}

        
        
        int getheight() {return height;}
        int getwidth() {return width;}
    protected:
        int height;
        int width;
        //tous les murs de la salle
        sf::RectangleShape murgauche;
        sf::RectangleShape murdroite;
        sf::RectangleShape murhaut;
        sf::RectangleShape murbas;
        //toutes les portes qu'elle peut avoir
        sf::RectangleShape portegauche;
        sf::RectangleShape portedroite;
        sf::RectangleShape portehaut;
        sf::RectangleShape portebas;
        //la sortie si elle en a une
        sf::RectangleShape sortie;

        sf::Sprite marchand; //konpranpas, ça devrait partir

        //attributs pour l'affichage
        sf::Sprite fond;
        std::string type; //pourquoi faire finalement ?
};