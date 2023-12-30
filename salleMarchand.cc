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

    
    texture = new sf::Texture;
    if (!texture->loadFromFile("marchand.png")) {
        std::cout<<"probleme avec texture"<<std::endl;
    }
    salle::marchand.setTexture(*texture);
    salle::marchand.setScale(width*0.2 / static_cast<float>(texture->getSize().x), width*0.2 / static_cast<float>(texture->getSize().x));
    salle::marchand.setPosition((width-salle::marchand.getGlobalBounds().width)/2,20.0f);

}

