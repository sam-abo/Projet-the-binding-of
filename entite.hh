 #pragma once

#include <SFML/Graphics.hpp>
#include "touches.hh"
#include "salle.hh"
#include "objet.hh"
//============================================================ un peu comme objet, très franchement pas grande utilité à part peut être pour les cinématiques
//importantes pour créer une histoire bien en lien avec ce qu'il y a autour des JO
// il faudra alors faire une fonction d'interraction entre le hero et les entités.
 
class Entity : public Objet {
public:
    //constructeurs
    // void pnj(float size, textureManager& textures, float x, float y, const salle* salle); 
    Entity(float size, textureManager& textures, float x, float y, const salle* salle); //pour les entités immobiles éventuellement.
    Entity();

    bool bords(salle* room, sf::Vector2f prevPositionEntity1);

    //void mouvement(Touches touche);
    
    // bool getQuest(){return HasQuest;};
    
    void deplacer(const sf::Vector2f& newPosition); //mettable dans objet en méthode virtuelle ?
    sf::Sprite getforme() {return forme;}; //pareil ?
    float& getSpeed(){return vitesse;};
    

    protected :
    float vitesse;
};