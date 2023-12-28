#include "Game.hh"

void Game :: jouer(){

    /*
    Afficher jeu;
    jeu.Fenetre_jeu("The binding of");

    // Load textures for the isometric tiles and characters
    sf::Texture tileTexture;
    if (!tileTexture.loadFromFile("path/to/tile_texture.png")) {
        std::cerr << "Failed to load tile texture" << std::endl;
        return;
    }

    sf::Texture heroTexture;
    if (!heroTexture.loadFromFile("path/to/hero_texture.png")) {
        std::cerr << "Failed to load hero texture" << std::endl;
        return;
    }

    // Set up the tile sprite
    sf::Sprite tileSprite(tileTexture);

    // Set up the hero sprite
    sf::Sprite heroSprite(heroTexture);
    heroSprite.setPosition(400, 300); // Starting position for the hero

    Touches key;
    std::vector<std::vector<std::pair<std::string, std::string>>> matrix = {
        // ... your existing matrix setup ...
    };
    carte carte(matrix, jeu.getWindow().getSize().x, jeu.getWindow().getSize().y);
    Hero hero(30.0f, sf::Color::Green, 200.0f, 100.0f, 1.0f);

    // Main game loop
    while (jeu.getWindow().isOpen()) {
        // Event handling
        sf::Event event;
        while (jeu.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                jeu.getWindow().close();
            }
        }

        jeu.getWindow().clear(sf::Color::Black);

        // Draw the isometric tiles
        for (int y = 0; y < jeu.getWindow().getSize().y; y += tileTexture.getSize().y) {
            for (int x = 0; x < jeu.getWindow().getSize().x; x += tileTexture.getSize().x) {
                tileSprite.setPosition(x, y);
                jeu.getWindow().draw(tileSprite);
            }
        }

        // Draw the hero
        jeu.getWindow().draw(heroSprite);

        // ... your existing entity drawing logic ...

        jeu.getWindow().display();
    }

*/




    
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;

    // Creation de la fenêtre SFML
    Afficher jeu;
    jeu.Fenetre_jeu("The binding of");
    Touches key;


    //"matrice des portes" on indique où seront les portes dans chaques salles, mais en soit ça décrit les propriétés de la salle,
    //c'est une matrice des propriétés des salles
    std::vector<std::vector<std::pair<std::string, std::string>>> matrix = {
        {{"bas", "droite"},{"bas", "gauchedroite"}, {"bas", "gauche"}},
        {{"hautbas", "droite"},{"hautbas", "gauchedroite"}, {"hautbas", "gauche"}},
        {{"haut", "droite"},{"haut", "gauchedroite"}, {"haut", "gauche"}}
    };

    //créer une carte qui est associée à une matrice, ici la matrice est définie au dessus, les 2 derniers trucs en paramètres sont là pour la taille des salles
    carte carte(matrix,screenWidth-100, screenHeight-100);
    
    

    // Creation de l'entite 1 : le perso principal
    Hero hero(screenWidth/100.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);
    
    //vecteur des entités présentes dans la salle
    std::vector<Objet> entities;
    //on déclare des entités et on spécifie dans quelle salle de la matrice de la carte associée elles sont. 
    //Peut être que c'est déplacable pour faire un truc plus élégant
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,carte.getsalleActive()));
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&carte.getgrille()[1][1]));



    // Boucle principale
    while (jeu.getWindow().isOpen()) {
        // Gestion des evenements
        jeu.fermeture(key);
        sf::Event event;
        while (jeu.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                jeu.getWindow().close();
            }
        }
        
        sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition();
        

        hero.mouvement(key);
        
        //ça ira dans une fonction dédiée dans entité.
        //Gestion des collisions avec les murs de la salle active.
        hero.collision(carte.getsalleActive()->Getmgauche().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmdroite().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmhaut().getGlobalBounds(),prevPositionEntity1);
        hero.collision(carte.getsalleActive()->Getmbas().getGlobalBounds(),prevPositionEntity1);

        //la fonction qui dit "si le machin passé en paramètre touches telle ou telle porte, il change de salle"
        carte.deplacementEntreSalle(&hero);
        
        
        jeu.getWindow().clear();
        
        //afficher la salle active
        jeu.dessiner_salle(carte.getsalleActive());
        //afficher le hero
        jeu.dessiner_obj(hero);
        //afficher les hp du hero
        jeu.afficherHP(hero);

        //boucle for qui gère l'affichage de toutes les entités présentes dans la salle active
        for (Objet& entite : entities) {
        if (entite.getSalleAppartenance() == carte.getsalleActive()) {
            jeu.dessiner_obj(entite);
            hero.collision(entite.getGlobalBounds(),prevPositionEntity1);
        }
        
    }
        jeu.getWindow().display();
    }
};
