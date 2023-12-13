#pragma once

#include <SFML/Graphics.hpp>
#include "entite.hh"

class Hero : public Entity {
public:
    Hero(float size, sf::Color color, float x, float y, float vitesse);
    Hero();
    int getHP(){return hp;};
    //window.draw(hpText);
    void afficherHP(sf::RenderWindow& window);
    void changersalle(salle* &salleActive, salle &newsalle, std::string direction);
    protected :
    int hp;
    //sf::Text hpText;
    //évantuellement d'autres attributs propre au héros comme son nom, sa capacité spéciale s'il en aura etc... bref
};