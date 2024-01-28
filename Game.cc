#include "Game.hh"
#include <cmath> 

void Game::game_design(Afficher& jeu, Hero& hero, sf::Vector2f prevPositionEntity1, Touches key){
        std::vector<Entity>& entities = carteActive->getEntities();
        std::vector<Enemy>& foes = carteActive->getFoes();
        std::vector<soin>& pack_soin = carteActive->getPackSoin();
        std::vector<matos>& items = carteActive->getmatos();
    //==================================================================================== chaque boucle est transformable en méthode.
    //une boucle qui gère l'affichage et l'intéraction avec toutes les entités de la map
        for ( Entity& entite : entities) {
            if (entite.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(entite);
                //jeu.afficher_quete(entite);
                hero.collision(entite.getGlobalBounds(), prevPositionEntity1);
            }
        }
    //une boucle qui gère l'affichage et l'intéraction avec tous les ennemis de la map
        for ( Enemy& mob : foes) {
            if (mob.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(mob);
                jeu.afficherHP(mob);
                jeu.dessiner_balles(mob.getBalles());
                mob.collision_balles(hero.getBalles());
                hero.mouv_ennemi(mob, prevPositionEntity1, *textures);
            }
        }
    //une boucle qui gère l'affichage de tous les objets de soin de la map
        for ( soin& pack : pack_soin) {
            if (pack.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(pack);
                jeu.afficher_heal(pack);
            }
        }
    //===========================================================================================
        for ( matos& trucs : items) {
            if (trucs.getSalleAppartenance() == carteActive->getsalleActive()) {
                jeu.dessiner_obj(trucs);
            }
        }
    //============================================================================================

        //================================================================================= méthodisables ?
        //les interractions spécifiques au héro. Les noms s'expliquent d'eux mêmes. 
        hero.tirer(key, foes, *textures, carteActive->getsalleActive());
        hero.collision_soin(pack_soin, carteActive->getsalleActive());
        hero.collision_items(items, carteActive->getsalleActive()); //

        //===================================================================== transformable en méthode. 
        //faire attention que la sortie ne se trouves pas toujours au même endroit, un générateur de onmbres aléatoires peut être bien
        if (items.empty()){ //si on a récupéré tous les items de la carte :
            cartes[numCarteActive].setSortie(); //la sortie apparait
        }
        //=====================================================================

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

    //============================================================================================
    //le setsortie est potentiellement à virer pour faire un level design plus intéressant
    //il s'agira juste de mettre un set sortie à d'autres endroits et sous conditions
    //cartes[0].setSortie(); //set sortie dit que l'objet numréro 0 du vecteur de cartes a une sortie et qu'on l'a mise à la fin de la map.
    //============================================================================================
    
    /*
    for(size_t k ; k < 6 ? ; i++){
        cartes[k].Init(i, *textures)
    }
    */
    cartes[0].Init(0, *textures); //init, donc j'ai accès à la  taille des salles

    cartes.push_back(carte(screenWidth-100, screenHeight-100,*textures)); //on ajoute une deuxième carte. On ne lui donne pas de sortie.
    cartes[1].Init(1,*textures);
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

    // Creation du héro: le perso principal
    Hero hero(screenWidth/25.0f, *textures, 200.0f, 100.0f,1.0f);
    

    // Boucle principale
    while (jeu.getWindow().isOpen()) {
      //  sf::Vector2f merchantPosition = salleMarchandInstance.getMerchantPosition();
        // Gestion des evenements
        jeu.fermeture(key);
        sf::Event event;
        while (jeu.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                jeu.getWindow().close();
            }
        }
        //gestion du menu (doit pouvoir servir aux cinématiques):
        if (debutJeu=="menu") {
            debutJeu = jeu.dessiner_menu(menu,event);
        }
        else if (debutJeu == "quitter"){jeu.getWindow().close();}
        else {
        
        //quelque chose qui sauvegarde en permanence l'ancienne position du héro
        sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition(); //plus pratique de l'avoir là vu le reste du code.
        
        //le héro peut bouger
        hero.mouvement(key);
        //fonction qui gère (pour chaque entitée d'ailleurs) la collision avec les murs de la salle active pour qu'il n'en sorte pas
        hero.bords(carteActive->getsalleActive(), prevPositionEntity1);

        //la fonction qui dit "si le machin passé en paramètre touches telle ou telle porte, il change de salle"
        //important de le phraser comme ça car ducoup ça peut concerner les ennemis.
        carteActive->deplacementEntreSalle(hero);

        //si le hero touche la sortie de la carte active alors on passe à la carte suivante.
        if (hero.getGlobalBounds().intersects(carteActive->getsalleActive()->Getsortie().getGlobalBounds())){
            //il faudrait prévoir un genre de free de tous les éléments de la carte active pour ne pas avoir de problème de mémoire.
            //le jeu ne devrait pas tout charger en même temps.
            //corps de fonction à changer pour faire l'appel potentiellement à d'autres niveaux ? ou a priori ça peut rester comme ça
            numCarteActive++;
            //libererMemoireCartePrecedente();
            carteActive=&cartes[numCarteActive];
            //si ça reste comme ça, mettre un if numCarteActive = genre 6 -> fin du jeu, passer à un écran de fin
        }
        
        //const float interactionThreshold = 50.0f; // Define the interaction threshold

    // Assuming salleMarchandInstance is correctly instantiated and accessible here
     //   sf::Vector2f merchantPosition = salleMarchandInstance.getMerchantPosition();

       // sf::Vector2f heroPosition = hero.getforme().getPosition();
        // You need to implement getMerchantPosition() in salleMarchand

      //  float distance = sqrt(pow(heroPosition.x - merchantPosition.x, 2) + pow(heroPosition.y - merchantPosition.y, 2));
      //  if (distance < interactionThreshold) { // interactionThreshold is the max distance to interact
            // Trigger interaction, like opening a dialogue box
       //     salleMarchandInstance.interact();
       // }
        
        jeu.getWindow().clear(); //? utile là ?
        
        //tous ces affichages sont potentiellement mettables dans une méthode de game ?

        //afficher la salle active
        jeu.dessiner_salle(carteActive->getsalleActive());
        //afficher le hero
        jeu.dessiner_obj(hero);
        //afficher les hp du hero
        jeu.afficherHP(hero);
        //afficher les balles du hero
        jeu.dessiner_balles(hero.getBalles());
        //c'est ici que le gros de chaque level tourne.
        game_design(jeu,hero,prevPositionEntity1, key);
        
        jeu.getWindow().display();
        }
    }
};
