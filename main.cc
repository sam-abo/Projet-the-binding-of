#include "carte.hh"
#include "salle.hh"
#include "entite.hh"
#include "hero.hh"

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Creation de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "SFML Deplacement d'Entite");

    salle s1(screenWidth-100, screenHeight-100, sf::Color::Red,1,0);

    salle s2(screenWidth-100, screenHeight-100, sf::Color::Blue,0,0);

    // Declaration de la salle active (initialisee à la première salle)
    salle* salleActive = &s1;

    // Creation de l'entite 1 : le perso principal
    Hero entite1(50.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);

    std::vector<Objet> entities;

    // Creation du 2eme truc via Objet
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,&s1));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&s1));


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

        entite1.mouvement();
        entite1.collision(s1.Getw1().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw2().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw3().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw4().getGlobalBounds(),prevPositionEntity1);


        // Verification de la frontière de la première salle
        if (entite1.getGlobalBounds().left < 25 && salleActive == &s1) {
            // Teleportez l'entite à la position specifiee dans la deuxième salle
            entite1.deplacer(sf::Vector2f(screenWidth-250,(screenHeight-100)/2));
            // Changez la salle active
            salleActive = &s2;
        }
        else if (entite1.getGlobalBounds().left+entite1.getGlobalBounds().width > screenWidth-125 
                && salleActive == &s2) {
            // Teleportez l'entite à la position specifiee dans la deuxième salle
            entite1.deplacer(sf::Vector2f(150,(screenHeight-100)/2));
            // Changez la salle active
            salleActive = &s1;
        }
        window.clear();
        // Dessinez la salle active
        salleActive->dessiner(window);
        //s1.dessiner(window);
        entite1.dessiner(window);
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