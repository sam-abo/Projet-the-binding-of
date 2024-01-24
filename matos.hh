#pragma once
#include "objet.hh"

class matos : public Objet {
public:
    //constructeur des différents matos qu'on va chercher.
    matos();
    matos(float x, float y, const salle* salle, textureManager& textures, std::string nom); //du matos qui est dnas une salle prédéfinie
    //du matos qui est associé uniquement à une salle, dans cette salle il devra y aboir un pnj ; dans cette salle il devra y avoir un pnj pour nous le donner.
    matos(const salle* salle, textureManager& textures, std::string nom);

    std::string getName(){return name;};

private :
    //éventuellement un truc style un bool pour dire si il a été récupéré ou pas.
    std::string name;
    size_t size = 10.0f; //aussi grand que les soins.
};