#include "carte.hh"
#include "salle.hh"
#include <iostream>
//#include "entite.hh"
#include "hero.hh"


int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Creation de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "SFML Deplacement d'Entite");

    std::vector<salle> salles;
    int numsalle;

    salle s1(screenWidth-100, screenHeight-100, sf::Color::Red,3,3);
    salles.push_back(s1);

    salle s2(screenWidth-100, screenHeight-100, sf::Color::Blue,3,3);
    salles.push_back(s2);

    salles.push_back(salle(screenWidth-100, screenHeight-100, sf::Color::Yellow,3,3));

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
    numsalle = 0;
    salle* salleActive = &salles[numsalle];

    // Creation de l'entite 1 : le perso principal
    Hero entite1(50.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);

    std::vector<Objet> entities;

    // Creation du 2eme truc via Objet
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,&salles[0]));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&salles[0]));

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
        sf::Vector2f prevPositionEntity1 = entite1.getforme().getPosition();

        // hpText.setString("HP: " + std::to_string(entite1.getHP()));
        // hpText.setPosition(prevPositionEntity1.x, prevPositionEntity1.y - 30);

        entite1.mouvement();
        entite1.collision(s1.Getw1().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw2().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw3().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw4().getGlobalBounds(),prevPositionEntity1);


        // Verification de la frontière de la première salle
        if(entite1.getGlobalBounds().intersects(salles[numsalle].Getp1().getGlobalBounds())){
            numsalle++;
            if(salles.size()<numsalle+1){
                std::cout << "oui\n" << std::endl;
                salles.push_back(salle(screenWidth-100, screenHeight-100, sf::Color::Yellow,3,3));
            }
            entite1.changersalle(salleActive,salles[numsalle],"gauche");
        }
        if(entite1.getGlobalBounds().intersects(salles[numsalle].Getp2().getGlobalBounds()) && numsalle>0){
            numsalle--;
            entite1.changersalle(salleActive,salles[numsalle],"droite");
        }
        
        window.clear();
        // Dessinez la salle active
        salleActive->dessiner(window);
        //s1.dessiner(window);
        entite1.dessiner(window);
        entite1.afficherHP(window);
        // window.draw(hpText);
        //entite1.afficherHP(window);
        for (Objet& entite : entities) {
        if (entite.getSalleAppartenance() == salleActive) {
            entite.dessiner(window);
            entite1.collision(entite.getGlobalBounds(),prevPositionEntity1);
        }
        
    }
        window.display();
    }
    return 0;
};