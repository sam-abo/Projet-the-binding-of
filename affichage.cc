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

void Afficher::dessiner_obj(Objet& obj){
    window.draw(obj.getforme());
}; //à mettre dans une classe affchage (objet)

void Afficher::dessiner_salle(salle* s) {
    window.draw(s->Getw1());
    window.draw(s->Getw2());
    window.draw(s->Getw3());
    window.draw(s->Getw4());
    window.draw(s->Getp1());
    window.draw(s->Getp2());
    window.draw(s->Getp3());
    window.draw(s->Getp4());
};
        
//sf::RenderWindow window(sf::VideoMode(screenWidth-100, screenHeight-100), "The binding of chatelêt les halles"); //dans la classe affichage (la fenêtre deu jeu)
void Afficher::Fenetre_jeu(std::string nom){
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktopMode.width;
    unsigned int screenHeight = desktopMode.height;
    window.create(sf::VideoMode(screenWidth-100, screenHeight-100), nom);
};