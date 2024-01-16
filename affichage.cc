#include "affichage.hh"

void Afficher::afficherHP(Hero& hero){
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    std::cout << "erreur d'accès à arial";
    // Gestion de l'erreur si la police ne peut pas être chargée
    return ;
    }
    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(24);
    hpText.setFillColor(sf::Color::Green);
    sf::Vector2f prevPositionEntity1 = hero.getforme().getPosition();
    hpText.setString("HP: " + std::to_string(hero.getHP()));
    hpText.setPosition(prevPositionEntity1.x, prevPositionEntity1.y - 30);
    window.draw(hpText);
 }; //à mettre dans une classe affchage (hero)

void Afficher::afficherHP(Enemy& foe){
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    std::cout << "erreur d'accès à arial";
    // Gestion de l'erreur si la police ne peut pas être chargée
    return ;
    }
    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(24);
    hpText.setFillColor(sf::Color::Red);
    sf::Vector2f prevPositionEntity1 = foe.getforme().getPosition();
    hpText.setString("HP: " + std::to_string(foe.getHP()));
    hpText.setPosition(prevPositionEntity1.x, prevPositionEntity1.y - 30);
    window.draw(hpText);
 };

void Afficher::dessiner_obj(Objet& obj){
    window.draw(obj.getforme());
};

void Afficher::dessiner_salle(salle* s) {
    window.draw(s->Getfond());
    window.draw(s->Getmhaut());
    window.draw(s->Getmbas());
    window.draw(s->Getmgauche());
    window.draw(s->Getmdroite());
    window.draw(s->Getphaut());
    window.draw(s->Getpbas());
    window.draw(s->Getpgauche());
    window.draw(s->Getpdroite());
    window.draw(s->Getsortie());
    
    window.draw(s->Getmarchand());

    // if(s->Getenemis()){
    //     window.draw(s->Getenemis()->getforme());
    // }
};

void Afficher::afficher_heal(soin& pack){
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
    std::cout << "erreur d'accès à arial";
    // Gestion de l'erreur si la police ne peut pas être chargée
    return ;
    }
    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(24);
    hpText.setFillColor(sf::Color::Green);
    sf::Vector2f prevPositionEntity1 = pack.getforme().getPosition();
    hpText.setString("+ " + std::to_string(pack.getHeal()) + "HP");
    hpText.setPosition(prevPositionEntity1.x, prevPositionEntity1.y - 30);
    window.draw(hpText);
 };

std::string Afficher::dessiner_menu(Menu& m, sf::Event& event){
    window.clear();
    window.draw(m.getfond());
    window.draw(m.getstartGameButton());
    window.draw(m.getexitButton());
    window.draw(m.getstartGameText());
    window.draw(m.getexitText());
    window.display();
    if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    return m.handleMouseClick(mousePosition.x, mousePosition.y);
                }
            }
    return "menu";
}

        
//sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "The binding of chatelêt les halles"); //dans la classe affichage (la fenêtre deu jeu)
void Afficher::Fenetre_jeu(std::string nom){
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;
    window.create(sf::VideoMode(screenWidth-100, screenHeight-100), nom);
};

void Afficher::dessiner_balles(std::vector<Balles>& balles) {
    //std::cout<<"on veut afficher une balle"<<std::endl;
    for (size_t i = 0; i < balles.size(); ++i) {
        //std::cout<<"on affiche une balle"<<std::endl;
        balles[i].deplacer();
        dessiner_obj(balles[i]); // Vous pouvez appeler dessiner_obj pour dessiner chaque balle
    }
}

void Afficher::fermeture (Touches touche){
    if(touche.isKeyPressed(esc)){
        window.close();
    }
};