
#pragma once
#include "objet.hh"
#include "entite.hh"

class matos : public Objet {
public:
    //constructeur des différents matos qu'on va chercher.
    matos();
    matos(float x, float y, const salle* salle, textureManager& textures, std::string nom); //du matos qui est dnas une salle prédéfinie
    matos(Entity& pnj); //du matos qu'une entité nous donnes lorsqu'on intérragit avec.

    std::string getName(){return name;};

private :
    //éventuellement un truc style un bool pour dire si il a été récupéré ou pas.
    std::string name;
    size_t size = 10.0f; //aussi grand que les soins.
};