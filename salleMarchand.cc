#include "salleMarchand.hh"

salleMarchand::salleMarchand(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas){
    salle::width = width;
    salle::height = height;
    salle::teleportPosition.x=width/2;
    salle::teleportPosition.y=height/2;
    
    // Création des murs
    creermur(murgauche,0.0f,0.0f,20.0f,height,color);
    creermur(murdroite,width-20.0f,0.0f,20.0f,height,color);
    creermur(murhaut,0.0f,0.0f,width, 20.0f,color);
    creermur(murbas,0.0f, height-20.0f,width, 20.0f,color);
    creerPorte(gauchedroite,hautbas);
    salle::marchand = new Entity(30.0,color,width/2,height/4,this);
    sf::Texture texture;
    if (!texture.loadFromFile("marchand.jpg")) {
        std::cout<<"probleme avec texture"<<std::endl;
    }
    //salle::marchand->setTexture(texture);
}

