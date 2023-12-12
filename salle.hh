#pragma once

#include <SFML/Graphics.hpp>
#include "carte.hh"

class salle : public carte {
    public:
        salle(int widht, int height, sf::Color color);
        void dessiner(sf::RenderWindow& window);
        sf::RectangleShape Getw1 () const {return wall1;}
        sf::RectangleShape Getw2 () const {return wall2;}
        sf::RectangleShape Getw3 () const {return wall3;}
        sf::RectangleShape Getw4 () const {return wall4;}
        sf::Vector2f& getTeleportPosition() {return teleportPosition;}
        salle* getDestination() const {return destination;}
        int getheight() {return height;}
        int getwidth() {return width;}
    private:
        int height;
        int width;
        sf::RectangleShape wall1;
        sf::RectangleShape wall2;
        sf::RectangleShape wall3;
        sf::RectangleShape wall4;
        sf::Vector2f teleportPosition;
        salle* destination;
};