#include "salleMarchand.hh"

salleMarchand::salleMarchand(int width, int height, sf::Color color,std::string gauchedroite, std::string hautbas, textureManager& textures){
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

    type = "salleMarchand";

    //salle::marchand.setTexture(*texture);
    salle::marchand.setTexture(textures.getTexture("marchand"));
    salle::marchand.setScale(width*0.2 / static_cast<float>(textures.getTexture("marchand").getSize().x), width*0.2 / static_cast<float>(textures.getTexture("marchand").getSize().x));
    salle::marchand.setPosition((width-salle::marchand.getGlobalBounds().width)/2,20.0f);
    salle::fond.setTexture(textures.getTexture("fond"));
    salle::fond.setScale(width / static_cast<float>(textures.getTexture("fond").getSize().x), height / static_cast<float>(textures.getTexture("fond").getSize().y));
    salle::fond.setPosition(0.0f,0.0f);
    


}

