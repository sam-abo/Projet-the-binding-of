#include "hero.hh"
#include "affichage.hh"

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Creation de la fenêtre SFML
    //sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "The binding of chatelêt les halles"); //dans la fonction affichage
    Afficher jeu;
    jeu.Fenetre_jeu("The binding of");
    salle s1(screenWidth-100, screenHeight-100, sf::Color::Red,3,3);

    salle s2(screenWidth-100, screenHeight-100, sf::Color::Blue,3,3);

    // Declaration de la salle active (initialisee à la première salle)
    salle* salleActive = &s1;

    // Creation de l'entite 1 : le perso principal
    Hero entite1(50.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);

    std::vector<Objet> entities;

    // Creation du 2eme truc via Objet
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,&s1));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&s1));


    // Boucle principale (à mettre dans une classe jeu)
    while (jeu.getWindow().isOpen()) {
        // Gestion des evenements
        sf::Event event;
        while (jeu.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                jeu.getWindow().close();
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
        entite1.changersalle(salleActive,s2,"gauche");
        entite1.changersalle(salleActive,s1,"droite");
        
        jeu.getWindow().clear();
        // Dessinez la salle active
        //salleActive->dessiner(window);
        jeu.dessiner_salle(salleActive);

        //entite1.dessiner(window);
        jeu.dessiner_obj(entite1);
        //entite1.afficherHP(window);
        jeu.afficherHP(entite1);

        for (Objet& entite : entities) {
        if (entite.getSalleAppartenance() == salleActive) {
            jeu.dessiner_obj(entite);
            entite1.collision(entite.getGlobalBounds(),prevPositionEntity1);
        }
        
    }
        jeu.getWindow().display();
    }
    return 0;
};