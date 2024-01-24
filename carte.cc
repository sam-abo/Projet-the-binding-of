#include "carte.hh"
#include "entite.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "salle.hh"

void carte::libererMemoire() {
        // Libérer la mémoire occupée par les vecteurs
        pack_soin.clear();
        foes.clear();
        entities.clear();

        // Supprimer les salles
        for (size_t i = 0; i < width; ++i) {
            delete[] grille[i];
        }
        delete[] grille;
    };


carte::carte(int widthsalle, int heightsalle, textureManager& textures) {
    // Initialisez la grille de salles
    width = configuration.size();
    height = configuration[0].size();
    numsalleheight=0;
    numsallewidth=0;
    configurerCarte(configuration,widthsalle,heightsalle, textures);
    salleActive = &grille[0][0];

    // entities.push_back(Entity(90.0f, textures, 800.0f, 500.0f,&grille[0][0]));
    // entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[0][0]));
    // entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[1][1]));
}

// void carte::ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string gauchedroite, std::string hautbas){
//     //grille[x][y] =new salle(widthsalle,heightsalle,color,gauchedroite,hautbas);
// }

void carte::configurerCarte(const std::vector<std::vector<std::pair<std::string, std::string>>>& config,int widthsalle, int heightsalle, textureManager& textures) {
    // Assurez-vous que la taille de la configuration correspond à la taille de la carte
    grille = new salle*[width];
    for (size_t x = 0; x < width; x++) {
        grille[x] = new salle[height];
        for (size_t y = 0; y < height; y++) {
            //grille[x][y]=new salle;
            // Utilisez la valeur de la configuration pour déterminer les paramètres de la salle
            if (x==0 && y==0){continue;};
            std::pair<std::string, std::string> valeur = config[x][y];
            grille[x][y] = salleEnemi(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures);
            //ajouterSalle(x ,y ,widthsalle, heightsalle, sf::Color::Blue, valeur.first, valeur.second);
        }
    }
    std::pair<std::string, std::string> valeur = config[0][0];
    grille[0][0]=salleMarchand(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures); //la 1ere salle de chaque carte sera une salle marchande
    
}

void carte::Init(size_t i, textureManager& textures){
    //switch case sur i pour appeler les fonction init1 à 5 et créer ! toutes ! les cartes donc le game design commences maintenant.
    switch(i) {
    case 0 :
        Init0(textures);
        break;
    case 1 :
        Init1(textures);
        break;
    // case 2 :
    //     Init2(textures);
    //     break;
    // case 3 :
    //     Init3(textures);
    //     break;
    // case 4 :
    //     Init4(textures);
    //     break;
    // case 5 :
    //     Init5(textures);
    //     break;
    // case 6 :
    //     Init6(textures);
    //     break;

    //entièrement déterministe, on aurait pu essayer de faire des choses qui mettent des ennemis au hasard, mais pas vraimet le temps de s'y pencher pour ce game_design
    
    }
};

void carte::Init0(textureManager& textures){
    //niveau un peu de découverte des quelques fonctionnalités de base quoi
    //vecteur d'entité de la carte 0
    entities.push_back(Entity(90.0f, textures, 800.0f, 500.0f,&grille[0][0]));
    entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[0][0]));
    entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[1][1]));
    //une entité qui possède un objet qu'elle va nous donner :
    entities.push_back(Entity(90.0f, textures, 730.0f, 600.0f,&grille[2][0]));

    //vecteur d'ennemi de la carte 0
    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,&grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,&grille[0][1], 0.35f, textures));

    //vecteur d'objets de soin de la carte 0 :
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[0][1], textures, 20));
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[1][0], textures, 40));   

    items.push_back(matos(362.0f,684.0f, &grille[2][2], textures,"carte étudiante"));    
    // items.push_back(entities.back().getItem()); 
    };


void carte::Init1(textureManager& textures){
    //premier vrai niveau
    //quelques ennemis ======================================================= il en faut beaucoup plus, faire des ennemis qui bougent (vite !), des ennemis qui bougent pas etc
    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,&grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 600.0f, 300.0f,&grille[1][1], 0.20f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,&grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 700.0f, 700.0f,&grille[0][2], 0.45f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 710.0f,&grille[0][1], 0.25f, textures));
    foes.push_back(Enemy(90.0f, 300.0f, 500.0f,&grille[2][1], 0.10f, textures));
    foes.push_back(Enemy(90.0f, 550.0f, 500.0f,&grille[2][2], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 800.0f, 460.0f,&grille[1][0], 0.85f, textures));
    

    //vecteur d'objets de soin de la carte 0 : ===================================== on verra
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[0][1], textures, 20));
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[1][0], textures, 40));      
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[0][2], textures, 10));
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[2][2], textures, 20));   
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[0][0], textures, 3));
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[1][1], textures, 12));   
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[2][1], textures, 20));
    pack_soin.push_back(soin(500.0f, 800.0f,&grille[1][2], textures, 4));   

    items.push_back(matos(456.0f,802.0f, &grille[1][2], textures,"pass navigo")); 

    //peut être une ou 2 entités au début du niveau ou dans d'autres salles pour parler avec elles et ettayer l'histoire. 
};

//=================================================== à transformer en overload operator ??
// void carte::print() {
//     for (int x = 0; x < width; x++) {
//         for (int y = 0; y < height; y++) {
//             //grille[x][y].print(widthsalle, heightsalle, valeur.second, valeur.first)
//         }
//     }
// }
//===================================================

void carte::deplacementEntreSalle(Hero &hero){
    if(hero.getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds())){
            numsalleheight--;
            
            hero.changersalle(salleActive,grille[numsallewidth][numsalleheight],"gauche");
        }
    if(hero.getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds())){
            numsalleheight++;
            hero.changersalle(salleActive,grille[numsallewidth][numsalleheight],"droite");
        }
    if(hero.getGlobalBounds().intersects(salleActive->Getpbas().getGlobalBounds())){
            numsallewidth++;
            hero.changersalle(salleActive,grille[numsallewidth][numsalleheight],"bas");

        }
    if(hero.getGlobalBounds().intersects(salleActive->Getphaut().getGlobalBounds())){
            numsallewidth--;
            hero.changersalle(salleActive,grille[numsallewidth][numsalleheight],"haut");
        }
};


