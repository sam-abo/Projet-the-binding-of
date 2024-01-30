#include "carte.hh"
#include "entite.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include "salle.hh"


// void carte::libererMemoire() {
//     // ... existing code for clearing vectors ...
//     // Libérer la mémoire occupée par les vecteurs
//         pack_soin.clear();
//         foes.clear();
//         entities.clear();

//     for (size_t i = 0; i < width; ++i) {
//         for (size_t j = 0; j < height; ++j) {
//             delete grille[i][j]; // Correctly using delete on pointers
//         }
//         delete[] grille[i];
//     }
//     delete[] grille;
// }


carte::carte(int widthsalle, int heightsalle, textureManager& textures) {
    // Initialisez la grille de salles
    width = configuration.size();
    height = configuration[0].size();
    numsalleheight=0;
    numsallewidth=0;
    configurerCarte(configuration,widthsalle,heightsalle, textures);
    salleActive = grille[0][0];

    // entities.push_back(Entity(90.0f, textures, 800.0f, 500.0f,&grille[0][0]));
    // entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[0][0]));
    // entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,&grille[1][1]));
}

// void carte::ajouterSalle(int x, int y, int widthsalle, int heightsalle, sf::Color color,std::string gauchedroite, std::string hautbas){
//     //grille[x][y] =new salle(widthsalle,heightsalle,color,gauchedroite,hautbas);
// }

void carte::configurerCarte(const std::vector<std::vector<std::pair<std::string, std::string>>>& config, int widthsalle, int heightsalle, textureManager& textures) {
    grille = new salle**[width];
    for (size_t x = 0; x < width; x++) {
        grille[x] = new salle*[height];
        for (size_t y = 0; y < height; y++) {
            std::pair<std::string, std::string> valeur = config[x][y];

            if (x == 0 && y == 0) {
                // The first room is always a merchant room
                grille[x][y] = new salleMarchand(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures);
            } else {
                // Other rooms are enemy rooms
                grille[x][y] = new salleEnemi(widthsalle, heightsalle, sf::Color::Black, valeur.second, valeur.first, textures);
            }
        }
    }
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
    case 2 :
        Init2(textures);
        break;
    case 3 :
        Init3(textures);
        break;
    case 4 :
        Init4(textures);
        break;
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
    entities.push_back(Entity(90.0f, textures, 800.0f, 500.0f,grille[0][0]));
    entities.push_back(Entity(90.0f, textures, 500.0f, 800.0f,grille[0][0]));

    //vecteur d'ennemi de la carte 0
    foes.push_back(Enemy(90.0f, 800.0f, 500.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 300.0f, 410.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 300.0f, 410.0f, grille[0][1], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 250.0f, 450.0f, grille[0][1], 0.70f, textures));
    foes.push_back(Enemy(90.0f, 400.0f, 320.0f, grille[0][1], 0.75f, textures));

    foes.push_back(Enemy(90.0f, 430.0f, 100.0f, grille[1][0], textures));
    foes.push_back(Enemy(90.0f, 710.0f, 210.0f, grille[1][0], textures));
    foes.push_back(Enemy(90.0f, 114.0f, 623.0f, grille[1][0], 0.55, textures));
    foes.push_back(Enemy(90.0f, 150.0f, 500.0f, grille[1][0], 0.60f, textures));
    foes.push_back(Enemy(90.0f, 200.0f, 300.0f, grille[1][0], 0.65f, textures));

    foes.push_back(Enemy(90.0f, 200.0f, 700.0f, grille[0][1], textures));
    foes.push_back(Enemy(90.0f, 300.0f, 410.0f, grille[0][1], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 350.0f, 500.0f, grille[0][1], 0.70f, textures));
    foes.push_back(Enemy(90.0f, 400.0f, 600.0f, grille[0][1], 0.75f, textures));

    foes.push_back(Enemy(90.0f, 207.0f, 580.0f, grille[2][1], textures));
    foes.push_back(Enemy(90.0f, 550.0f, 500.0f, grille[2][2], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 810.0f, 453.0f, grille[2][0], 0.85f, textures));
    foes.push_back(Enemy(90.0f, 600.0f, 320.0f, grille[2][0], 0.90f, textures));
    foes.push_back(Enemy(90.0f, 700.0f, 400.0f, grille[2][0], 0.95f, textures));

// Ajoutez autant d'ennemis que nécessaire...

    

    //vecteur d'objets de soin de la carte 0 :
    pack_soin.push_back(soin(500.0f, 800.0f,grille[0][1], textures, 20));
    pack_soin.push_back(soin(500.0f, 800.0f,grille[1][0], textures, 40));   

    items.push_back(matos(362.0f,684.0f, grille[2][2], textures,"carte etudiante"));
    };


void carte::Init1(textureManager& textures){
    //premier vrai niveau
    //quelques ennemis ======================================================= il en faut beaucoup plus, faire des ennemis qui bougent (vite !), des ennemis qui bougent pas etc
    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 600.0f, 300.0f,grille[1][1], 0.50f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 500.0f,grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 700.0f, 700.0f,grille[0][2], 0.45f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 710.0f,grille[0][1], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 300.0f, 500.0f,grille[2][1], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 550.0f, 500.0f,grille[2][2], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 800.0f, 460.0f,grille[1][0], 0.85f, textures));
    

    //vecteur d'objets de soin de la carte 1 : ===================================== on verra
    pack_soin.push_back(soin(500.0f, 800.0f,grille[0][1], textures, 5));
    pack_soin.push_back(soin(500.0f, 800.0f,grille[1][0], textures, 4));      
    pack_soin.push_back(soin(500.0f, 800.0f,grille[0][2], textures, 1));
    pack_soin.push_back(soin(500.0f, 800.0f,grille[2][2], textures, 10));   
    pack_soin.push_back(soin(500.0f, 800.0f,grille[0][0], textures, 3));
    pack_soin.push_back(soin(500.0f, 800.0f,grille[1][1], textures, 3));   
    pack_soin.push_back(soin(500.0f, 800.0f,grille[2][1], textures, 6));
    pack_soin.push_back(soin(500.0f, 800.0f,grille[1][2], textures, 2));   

    items.push_back(matos(456.0f,802.0f, grille[1][2], textures,"pass navigo")); 

    //peut être une ou 2 entités au début du niveau ou dans d'autres salles pour parler avec elles et ettayer l'histoire. 
};


void carte::Init2(textureManager& textures){
    //premier vrai niveau
    //quelques ennemis ======================================================= il en faut beaucoup plus, faire des ennemis qui bougent (vite !), des ennemis qui bougent pas etc
    foes.push_back(Enemy(90.0f, 700.0f, 300.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 400.0f, 200.0f, grille[1][1], 0.50f, textures));
    foes.push_back(Enemy(90.0f, 350.0f, 180.0f, grille[1][1], 0.55f, textures));

    foes.push_back(Enemy(90.0f, 500.0f, 700.0f, grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 600.0f, 400.0f, grille[0][2], 0.45f, textures));
    foes.push_back(Enemy(90.0f, 650.0f, 350.0f, grille[0][2], 0.50f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 710.0f, grille[0][1], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 300.0f, 500.0f, grille[2][1], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 550.0f, 500.0f, grille[2][2], 0.55f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 460.0f, grille[1][0], 0.85f, textures));
    foes.push_back(Enemy(90.0f, 750.0f, 420.0f, grille[1][0], 0.90f, textures));
    foes.push_back(Enemy(90.0f, 700.0f, 480.0f, grille[1][0], 0.95f, textures));


// Vecteur d'objets de soin de la carte :

    pack_soin.push_back(soin(300.0f, 500.0f, grille[0][1], textures, 3));
    pack_soin.push_back(soin(700.0f, 200.0f, grille[1][0], textures, 8));
    pack_soin.push_back(soin(600.0f, 700.0f, grille[0][2], textures, 2));
    pack_soin.push_back(soin(400.0f, 400.0f, grille[2][2], textures, 6));
    pack_soin.push_back(soin(200.0f, 100.0f, grille[0][0], textures, 1));
    pack_soin.push_back(soin(3450.0f, 302.0f, grille[1][1], textures, 4));
    pack_soin.push_back(soin(500.0f, 700.0f, grille[2][1], textures, 7));
    pack_soin.push_back(soin(600.0f, 500.0f, grille[1][2], textures, 5));
 
    
    items.push_back(matos(456.0f,802.0f, grille[2][1], textures,"keys")); 
};

void carte::Init3(textureManager& textures){
    foes.push_back(Enemy(90.0f, 700.0f, 300.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 400.0f, 200.0f, grille[1][1], 0.50f, textures));

    foes.push_back(Enemy(90.0f, 500.0f, 700.0f, grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 600.0f, 400.0f, grille[0][2], 0.45f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 710.0f, grille[0][1], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 300.0f, 500.0f, grille[2][1], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 550.0f, 500.0f, grille[2][2], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 800.0f, 460.0f, grille[1][0], textures));

    foes.push_back(Enemy(90.0f, 200.0f, 300.0f, grille[2][0], textures));
    foes.push_back(Enemy(90.0f, 700.0f, 550.0f, grille[2][1], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 500.0f, 400.0f, grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 900.0f, 620.0f, grille[1][0], 0.65f, textures));

    foes.push_back(Enemy(90.0f, 300.0f, 500.0f, grille[1][2], 0.45f, textures));
    foes.push_back(Enemy(90.0f, 550.0f, 400.0f, grille[2][0], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 750.0f, 650.0f, grille[1][2], textures));


// Vecteur d'objets de soin de la carte :

pack_soin.push_back(soin(300.0f, 500.0f, grille[0][1], textures, 3));
pack_soin.push_back(soin(700.0f, 200.0f, grille[1][0], textures, 8));
pack_soin.push_back(soin(600.0f, 700.0f, grille[0][2], textures, 2));
pack_soin.push_back(soin(400.0f, 400.0f, grille[2][2], textures, 6));
pack_soin.push_back(soin(200.0f, 100.0f, grille[0][0], textures, 1));
pack_soin.push_back(soin(3450.0f, 302.0f, grille[1][1], textures, 4));
pack_soin.push_back(soin(500.0f, 700.0f, grille[2][1], textures, 7));
pack_soin.push_back(soin(600.0f, 500.0f, grille[1][2], textures, 5));

items.push_back(matos(200.0f, 500.0f, grille[0][2], textures, "piece_id"));
};

void carte::Init4(textureManager& textures){
    foes.push_back(Enemy(90.0f, 650.0f, 200.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 300.0f, 150.0f, grille[1][1], 0.60f, textures));

    foes.push_back(Enemy(90.0f, 450.0f, 750.0f, grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 700.0f, 350.0f, grille[0][2], 0.55f, textures));

    foes.push_back(Enemy(90.0f, 850.0f, 700.0f, grille[0][1], 0.75f, textures));
    foes.push_back(Enemy(90.0f, 400.0f, 550.0f, grille[2][1], 0.45f, textures));
    foes.push_back(Enemy(90.0f, 600.0f, 500.0f, grille[2][2], 0.50f, textures));
    foes.push_back(Enemy(90.0f, 900.0f, 420.0f, grille[1][0], 0.80f, textures));

    // Vecteur d'objets de soin de la carte :

    pack_soin.push_back(soin(350.0f, 600.0f, grille[0][1], textures, 5));
    pack_soin.push_back(soin(800.0f, 250.0f, grille[1][0], textures, 7));
    pack_soin.push_back(soin(700.0f, 800.0f, grille[0][2], textures, 3));
    pack_soin.push_back(soin(500.0f, 400.0f, grille[2][2], textures, 9));
    pack_soin.push_back(soin(300.0f, 100.0f, grille[0][0], textures, 2));
    pack_soin.push_back(soin(400.0f, 600.0f, grille[1][1], textures, 6));
    pack_soin.push_back(soin(650.0f, 550.0f, grille[2][1], textures, 4));
    pack_soin.push_back(soin(750.0f, 500.0f, grille[1][2], textures, 8));

//items.push_back(matos(500.0f, 700.0f, grille[0][0], textures, "piece_id"));
}

void carte::Init5(textureManager& textures){
    foes.push_back(Enemy(90.0f, 600.0f, 250.0f, grille[1][1], textures));
    foes.push_back(Enemy(90.0f, 350.0f, 180.0f, grille[1][1], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 450.0f, 120.0f, grille[1][1], textures));

    foes.push_back(Enemy(90.0f, 500.0f, 800.0f, grille[0][2], textures));
    foes.push_back(Enemy(90.0f, 650.0f, 350.0f, grille[0][2], 0.10f, textures));
    foes.push_back(Enemy(90.0f, 720.0f, 600.0f, grille[0][2], 0.65f, textures));

    foes.push_back(Enemy(90.0f, 800.0f, 700.0f, grille[0][1], textures));

    foes.push_back(Enemy(90.0f, 700.0f, 550.0f, grille[2][1], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 400.0f, 600.0f, grille[2][1], 0.35f, textures));

    foes.push_back(Enemy(90.0f, 900.0f, 620.0f, grille[1][0], 0.65f, textures));
    foes.push_back(Enemy(90.0f, 900.0f, 420.0f, grille[1][0], textures));

    foes.push_back(Enemy(90.0f, 300.0f, 500.0f, grille[1][2], 0.45f, textures));
    foes.push_back(Enemy(90.0f, 750.0f, 650.0f, grille[1][2], 0.40f, textures));
    foes.push_back(Enemy(90.0f, 450.0f, 120.0f, grille[1][2], textures));

    foes.push_back(Enemy(90.0f, 550.0f, 400.0f, grille[2][0], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 200.0f, 300.0f, grille[2][0], textures));
    
    foes.push_back(Enemy(90.0f, 500.0f, 400.0f, grille[2][2], 0.55f, textures));
    foes.push_back(Enemy(90.0f, 600.0f, 550.0f, grille[2][2], 0.60f, textures));

}


void carte::deplacementEntreSalle(Hero &hero) {
    if(hero.getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds())) {
        numsalleheight--;
        hero.changersalle(salleActive, *grille[numsallewidth][numsalleheight], "gauche");
    }
    if(hero.getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds())) {
        numsalleheight++;
        hero.changersalle(salleActive, *grille[numsallewidth][numsalleheight], "droite");
    }
    if(hero.getGlobalBounds().intersects(salleActive->Getpbas().getGlobalBounds())) {
        numsallewidth++;
        hero.changersalle(salleActive, *grille[numsallewidth][numsalleheight], "bas");
    }
    if(hero.getGlobalBounds().intersects(salleActive->Getphaut().getGlobalBounds())) {
        numsallewidth--;
        hero.changersalle(salleActive, *grille[numsallewidth][numsalleheight], "haut");
    }
};

void carte:: destruct_enemi(){
    std::vector<size_t> indices_a_supprimer;
    for (size_t i = 0; i < foes.size(); ++i) {
        if (foes[i].getHP() == 0) {
            
            indices_a_supprimer.push_back(i);
        }
    }

    // Supprimer les balles après la boucle
    for (auto it = indices_a_supprimer.rbegin(); it != indices_a_supprimer.rend(); ++it) {
        foes.erase(foes.begin() + *it);
    }
};


