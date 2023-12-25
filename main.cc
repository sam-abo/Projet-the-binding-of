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
    

    // Declaration de la salle active (initialisee à la première salle)
    int numsalle = 0;
    int numsallewidth = 0;
    int numsalleheight = 0;
    
    salle* salleActive = &carte.getgrille()[0][0];
    
    
    carte.getsalleActive()->print();

    // Creation de l'entite 1 : le perso principal
    Hero hero(screenWidth/100.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);
    

    std::vector<Objet> entities;

    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&carte.getgrille()[1][1]));



    // Boucle principale
    while (window.isOpen()) {
        // Gestion des evenements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition();
        

        hero.mouvement();
        
        hero.collision(carte.getsalleActive()->Getmgauche().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmdroite().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmhaut().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmbas().getGlobalBounds(),prevPositionEntity1);

        
        carte.deplacementEntreSalle(&hero);
        
        
        window.clear();
        
        carte.getsalleActive()->dessiner(window);
        
        hero.dessiner(window);
        hero.afficherHP(window);

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