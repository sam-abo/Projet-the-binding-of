#include "Game.hh"

void Game::game_design(Afficher& jeu, Hero& hero, sf::Vector2f prevPositionEntity1, Touches key){
        std::vector<Entity>& entities = carteActive->getEntities();
        std::vector<Enemy>& foes = carteActive->getFoes();
        std::vector<soin>& pack_soin = carteActive->getPackSoin();

        for ( Entity& entite : entities) {
            if (entite.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(entite);
                hero.collision(entite.getGlobalBounds(), prevPositionEntity1);
            }
        }

        for ( Enemy& mob : foes) {
            if (mob.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(mob);
                jeu.afficherHP(mob);
                mob.collision_balles(hero.getBalles());
                hero.mouv_ennemi(mob, prevPositionEntity1);
            }
        }

        for ( soin& pack : pack_soin) {
            if (pack.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(pack);
                jeu.afficher_heal(pack);
            }
        }
        hero.tirer(key, foes, *textures, carteActive->getsalleActive()); //va créer des balles
        hero.collision_soin(pack_soin, carteActive->getsalleActive());
}

Game::Game(int i){
    //charger l'objet de toutes les textures
    textures = new textureManager;
    textures->chargerToutesTextures();
    debutJeu = "menu";
    //mettre en place les paramètres qui permettent d'afficher le jeu aux bonnes proportions sur l'écran
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    screenWidth = desktopMode.width;
    screenHeight = desktopMode.height;

    numCarteActive=0; //numCarteActive sers à dire à lobjet game quelle est la carte sur laquelle on évolue actuellement. il servira pour les changements de carte
    //game a un attribut vecteur de cartes
    cartes.push_back(carte(screenWidth-100, screenHeight-100,*textures));    
    cartes[0].setSortie(); //set sortie dit que l'objet numréro 0 du vecteur de cartes a une sortie et qu'on l'a mise à la fin de la map.
    cartes[0].Init(0, *textures);
    cartes.push_back(carte(screenWidth-100, screenHeight-100,*textures)); //on ajoute une deuxième carte. On ne lui donne pas de sortie.
    carteActive = &cartes[0]; //on définit la carte active comme la 1ère du vecteur de cartes.
}

void Game :: jouer(){
    //idéalement, jouer devient juste une fonction avec niveau1 2 3 jusqu'à disons 5.
    //avec une fonction qui fait passer de niveau en niveau quand on atteint la sortie avec si possible une cinématique dedans.



    // Creation de la fenêtre SFML avec son nom et de l'objet pour les touches du clavier
    Afficher jeu;
    jeu.Fenetre_jeu("The binding of");
    Touches key;

    Menu menu(screenWidth-100,screenHeight-100, *textures);

    // Creation de l'entite 1 : le perso principal
    Hero hero(screenWidth/25.0f, *textures, 200.0f, 100.0f,1.0f);
    

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
        carteActive->deplacementEntreSalle(hero);

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
        //afficher les balles du hero
        jeu.dessiner_balles(hero.getBalles());

        this->game_design(jeu,hero,prevPositionEntity1, key);
        
        jeu.getWindow().display();
        }
    }
};
