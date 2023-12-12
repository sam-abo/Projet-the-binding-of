#include "carte.hh"
#include "salle.hh"
#include "entité.hh"

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "SFML Déplacement d'Entité");

    salle s1(screenWidth-100, screenHeight-100, sf::Color::Red);

    salle s2(screenWidth-100, screenHeight-100, sf::Color::Blue);

    // Déclaration de la salle active (initialisée à la première salle)
    salle* salleActive = &s1;

    // Création de l'entité 1 : le perso principal
    Entity entite1(50.0f, sf::Color::Green, 200.0f, 100.0f,0.5f);

    std::vector<Entity> entites;

    // Création de l'entité 2
    entites.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,&s1));

    // Boucle principale
    while (window.isOpen()) {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Enregistrement de la position précédente de l'entité 1
        sf::Vector2f prevPositionEntity1 = entite1.getforme().getPosition();

        entite1.mouvement();
        entite1.collision(s1.Getw1().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw2().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw3().getGlobalBounds(),prevPositionEntity1);
        entite1.collision(s1.Getw4().getGlobalBounds(),prevPositionEntity1);


        // Vérification de la frontière de la première salle
        if (entite1.getGlobalBounds().left < 25 && salleActive == &s1) {
            // Téléportez l'entité à la position spécifiée dans la deuxième salle
            entite1.déplacer(sf::Vector2f(screenWidth-250,(screenHeight-100)/2));
            // Changez la salle active
            salleActive = &s2;
        }
        else if (entite1.getGlobalBounds().left+entite1.getGlobalBounds().width > screenWidth-125 
                && salleActive == &s2) {
            // Téléportez l'entité à la position spécifiée dans la deuxième salle
            entite1.déplacer(sf::Vector2f(150,(screenHeight-100)/2));
            // Changez la salle active
            salleActive = &s1;
        }
        window.clear();
        // Dessinez la salle active
        salleActive->dessiner(window);
        //s1.dessiner(window);
        entite1.dessiner(window);
        for (Entity& entite : entites) {
        if (entite.getSalleAppartenance() == salleActive) {
            entite.dessiner(window);
            entite1.collision(entite.getGlobalBounds(),prevPositionEntity1);
        }
    }
        window.display();
    }
    return 0;
};