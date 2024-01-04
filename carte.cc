#include "carte.hh"
#include <iostream>
//#include "salle.hh"

carte::carte(const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration,int widthsalle, int heightsalle, textureManager& textures) {
    // Initialisez la grille de salles
    width = configuration.size();
    height = configuration[0].size();
    numsalleheight=0;
    numsallewidth=0;
    configurerCarte(configuration,widthsalle,heightsalle, textures);
    salleActive = &grille[0][0];
}

void carte::ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string gauchedroite, std::string hautbas){
    //grille[x][y] =new salle(widthsalle,heightsalle,color,gauchedroite,hautbas);
}

void carte::configurerCarte(const std::vector<std::vector<std::pair<std::string, std::string>>>& configuration,int widthsalle, int heightsalle, textureManager& textures) {
    // Assurez-vous que la taille de la configuration correspond à la taille de la carte
    grille = new salle*[width];
    for (int x = 0; x < width; x++) {
        grille[x] = new salle[height];
        for (int y = 0; y < height; y++) {
            //grille[x][y]=new salle;
            // Utilisez la valeur de la configuration pour déterminer les paramètres de la salle
            if (x==0 && y==0){continue;};
            std::pair<std::string, std::string> valeur = configuration[x][y];
            grille[x][y] = salleEnemi(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures);
            //ajouterSalle(x ,y ,widthsalle, heightsalle, sf::Color::Blue, valeur.first, valeur.second);
        }
    }
    std::pair<std::string, std::string> valeur = configuration[0][0];
    grille[0][0]=salleMarchand(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures); //la 1ere salle de chaque carte sera une salle marchande
    
}
void carte::print() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            //grille[x][y].print(widthsalle, heightsalle, valeur.second, valeur.first)
        }
    }
}

void carte::deplacementEntreSalle(Hero *hero){
    if(hero->getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds())){
            numsalleheight--;
            
            hero->changersalle(salleActive,grille[numsallewidth][numsalleheight],"gauche");
        }
    if(hero->getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds())){
            numsalleheight++;
            hero->changersalle(salleActive,grille[numsallewidth][numsalleheight],"droite");
        }
    if(hero->getGlobalBounds().intersects(salleActive->Getpbas().getGlobalBounds())){
            numsallewidth++;
            hero->changersalle(salleActive,grille[numsallewidth][numsalleheight],"bas");

        }
    if(hero->getGlobalBounds().intersects(salleActive->Getphaut().getGlobalBounds())){
            numsallewidth--;
            hero->changersalle(salleActive,grille[numsallewidth][numsalleheight],"haut");
        }
};


