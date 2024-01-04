#include "Game.hh"

Game::Game(int i){
    debutJeu = "menu";
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    screenWidth = desktopMode.width;
    screenHeight = desktopMode.height;

    //"matrice des portes" on indique où seront les portes dans chaques salles, mais en soit ça décrit les propriétés de la salle,
    //c'est une matrice des propriétés des salles
    std::vector<std::vector<std::pair<std::string, std::string>>> matrix = {
        {{"bas", "droite"},{"bas", "gauchedroite"}, {"bas", "gauche"}},
        {{"hautbas", "droite"},{"hautbas", "gauchedroite"}, {"hautbas", "gauche"}},
        {{"haut", "droite"},{"haut", "gauchedroite"}, {"haut", "gauche"}}
    };

    //créer une carte qui est associée à une matrice, ici la matrice est définie au dessus, les 2 derniers trucs en paramètres sont là pour la taille des salles
    textures = new textureManager;
    textures->chargerToutesTextures();
    numCarteActive=0;
    cartes.push_back(carte(matrix,screenWidth-100, screenHeight-100,*textures));
    cartes[0].setSortie();
    cartes.push_back(carte(matrix,screenWidth-100, screenHeight-100,*textures));
    carteActive = &cartes[0];
}

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




    // Creation de la fenêtre SFML
    Afficher jeu;
    jeu.Fenetre_jeu("The binding of");
    Touches key;

    Menu menu(screenWidth-100,screenHeight-100);

    // Creation de l'entite 1 : le perso principal
    Hero hero(screenWidth/100.0f, sf::Color::Green, 200.0f, 100.0f,1.0f);
    
    //vecteur des entités présentes dans la salle
    std::vector<Objet> entities;
    //on déclare des entités et on spécifie dans quelle salle de la matrice de la carte associée elles sont. 
    //Peut être que c'est déplacable pour faire un truc plus élégant
    entities.push_back(Entity(30.0f, sf::Color::Blue, 800.0f, 500.0f,carteActive->getsalleActive())); //une entitée bleue
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,carteActive->getsalleActive())); //un objet jaune
    entities.push_back(Objet(30.0f, sf::Color::Yellow, 500.0f, 800.0f,&cartes[0].getgrille()[1][1])); //un objet jaune

    std::vector<Enemy> foes;
    foes.push_back(Enemy(30.0f, 800.0f, 500.0f,&cartes[0].getgrille()[1][1]));


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

        if (debutJeu=="menu") {
            debutJeu = jeu.dessiner_menu(menu,event);
        }
        else if (debutJeu == "quitter"){jeu.getWindow().close();}
        else {
        
        sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition();
        

        hero.mouvement(key);

        //fonction qui gère (pour chaque entitée d'ailleurs) la collision avec les murs de la salle active
        hero.bords(carteActive->getsalleActive(), prevPositionEntity1);

        //la fonction qui dit "si le machin passé en paramètre touches telle ou telle porte, il change de salle"
        carteActive->deplacementEntreSalle(&hero);

        //si le hero touche la sortie de la carte active alors numcCarteActive ++ et la carte active est updaté
        if (hero.getGlobalBounds().intersects(carteActive->getsalleActive()->Getsortie().getGlobalBounds())){
            numCarteActive++;
            carteActive=&cartes[numCarteActive];
        }
        
        
        jeu.getWindow().clear();
        
        //afficher la salle active
        jeu.dessiner_salle(carteActive->getsalleActive());
        //afficher le hero
        jeu.dessiner_obj(hero);
        //afficher les hp du hero
        jeu.afficherHP(hero);

        //boucle for qui gère l'affichage de toutes les entités présentes dans la salle active
        for (Objet& entite : entities) {
            if (entite.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(entite);
                hero.collision(entite.getGlobalBounds(),prevPositionEntity1);
                } 
            }
        for (Enemy& mob : foes){
            if (mob.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(mob);
                jeu.afficherHP(mob);
                //hero.collision(mob.getGlobalBounds(),prevPositionEntity1);
                hero.coll_ennemi(mob,prevPositionEntity1);
                } 
        }
        
        jeu.getWindow().display();
        }
    }
};
