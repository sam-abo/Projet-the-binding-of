#include "carte.hh"
#include "salle.hh"
#include <iostream>
#include "hero.hh"


int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Creation de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "SFML Deplacement d'Entite");

    std::vector<salle> salles;

    std::vector<std::vector<std::pair<std::string, std::string>>> matrix = {
        {{"bas", "droite"},{"bas", "gauchedroite"}, {"bas", "gauche"}},
        {{"hautbas", "droite"},{"hautbas", "gauchedroite"}, {"hautbas", "gauche"}},
        {{"haut", "droite"},{"haut", "gauchedroite"}, {"haut", "gauche"}}
    };

    carte carte(matrix,screenWidth-100, screenHeight-100);

    salle s1(screenWidth-100, screenHeight-100, sf::Color::Red,"gauchedroite","hautbas");
    salles.push_back(s1);

    salle s2(screenWidth-100, screenHeight-100, sf::Color::Blue,"gauchedroite","hautbas");
    salles.push_back(s2);

    
    //std::vector<std::vector<salle>> grille;
    // salle grille[matrix.size()][matrix[0].size()];

    // for (int x = 0; x < matrix.size(); x++) {
    //     //grille.push_back(std::vector<salle>());
    //     for (int y = 0; y < matrix[0].size(); y++) {
    //         //grille[x][y]=new salle;
    //         // Utilisez la valeur de la configuration pour déterminer les paramètres de la salle
    //         std::pair<std::string, std::string> valeur = matrix[x][y];
    //         grille[x][y]=salle(screenWidth-100, screenHeight-100, sf::Color::Blue, valeur.second, valeur.first);
    //         //ajouterSalle(x ,y ,widthsalle, heightsalle, sf::Color::Blue, valeur.first, valeur.second);
    //     }
    // }

    //salles.push_back(salle(screenWidth-100, screenHeight-100, sf::Color::Yellow,"gauchedroite","hautbas"));

    //gestion des textes :
    // sf::Font font;
    // if (!font.loadFromFile("arial.ttf")) {
    // // Gestion de l'erreur si la police ne peut pas être chargée
    // return -1;
    // }
    // sf::Text hpText;
    // hpText.setFont(font);
    // hpText.setCharacterSize(24);
    // hpText.setFillColor(sf::Color::Green);

    // Declaration de la salle active (initialisee à la première salle)
    int numsalle = 0;
    int numsallewidth = 0;
    int numsalleheight = 0;
    //salle* salleActive = &salles[numsalle];
    //std::cout<<"oui"<<std::endl;
    salle* salleActive = &carte.getgrille()[0][0];
    //carte.setsalleActive(carte.getgrille()[0][0]);
    //std::cout<<"oui"<<std::endl;
    //salleActive = &salles[numsalle];
    carte.getsalleActive()->print();

    // Creation de l'entite 1 : le perso principal
    Hero hero(screenWidth/100.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);
    

    std::vector<Objet> entities;

    // Creation du 2eme truc via Objet
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&carte.getgrille()[1][1]));

    // Creation de l'entite 2
    //entites.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,&salles[0]));


    // Boucle principale
    while (window.isOpen()) {
        // Gestion des evenements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Enregistrement de la position precedente de l'entite 1
        sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition();

        // hpText.setString("HP: " + std::to_string(hero.getHP()));
        // hpText.setPosition(prevPositionEntity1.x, prevPositionEntity1.y - 30);

        hero.mouvement();
        //std::cout<<"oui"<<std::endl;
        hero.collision(carte.getsalleActive()->Getmgauche().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmdroite().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmhaut().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmbas().getGlobalBounds(),prevPositionEntity1);


        // Verification de la frontière de la première salle
        /*
        if(hero.getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds())){
            numsalle++;
            
            hero.changersalle(salleActive,salles[numsalle],"gauche");
        }
        if(hero.getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds()) && numsalle>0){
            numsalle--;
            hero.changersalle(salleActive,salles[numsalle],"droite");
        }*/
        
        carte.deplacementEntreSalle(&hero);/*
        if(hero.getGlobalBounds().intersects(salleActive->Getpgauche().getGlobalBounds())){
            numsalleheight--;
            
            hero.changersalle(salleActive,carte.getgrille()[numsallewidth][numsalleheight],"gauche");
        }
        if(hero.getGlobalBounds().intersects(salleActive->Getpdroite().getGlobalBounds())){
            numsalleheight++;
            hero.changersalle(salleActive,carte.getgrille()[numsallewidth][numsalleheight],"droite");
        }
        if(hero.getGlobalBounds().intersects(salleActive->Getpbas().getGlobalBounds())){
            numsallewidth++;
            std::cout<<"ouioui"<<std::endl;
            
            hero.changersalle(salleActive,carte.getgrille()[numsallewidth][numsalleheight],"bas");
        }
        if(hero.getGlobalBounds().intersects(salleActive->Getphaut().getGlobalBounds())){
            numsallewidth--;
            hero.changersalle(salleActive,carte.getgrille()[numsallewidth][numsalleheight],"haut");
        }*/
        
        window.clear();
        // Dessinez la salle active
        //std::cout<<"ouioui"<<std::endl;
        carte.getsalleActive()->dessiner(window);
        //s1.dessiner(window);
        hero.dessiner(window);
        hero.afficherHP(window);
        // window.draw(hpText);
        //hero.afficherHP(window);
        for (Objet& entite : entities) {
        if (entite.getSalleAppartenance() == carte.getsalleActive()) {
            entite.dessiner(window);
            hero.collision(entite.getGlobalBounds(),prevPositionEntity1);
        }
        
    }
        window.display();
    }
    return 0;
};