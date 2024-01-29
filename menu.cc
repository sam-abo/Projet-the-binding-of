#include "menu.hh"

Menu::Menu(int width, int height,textureManager& textures) {
        font.loadFromFile("textures/arial.ttf"); // Assurez-vous de charger une police valide

        this->width = width;
        this->height = height;
        // Bouton "Start Game"
        startGameButton.setSize(sf::Vector2f(200.f, 50.f));
        startGameButton.setPosition(width / 8 - 100, height / 1.1 - 75);
        startGameButton.setFillColor(sf::Color::Green);

        // Bouton "Exit"
        exitButton.setSize(sf::Vector2f(200.f, 50.f));
        exitButton.setPosition(width / 8 - 100, height / 1.1 + 25);
        exitButton.setFillColor(sf::Color::Red);

        // Textes des boutons
        startGameText.setFont(font);
        startGameText.setString("Start Game");
        startGameText.setCharacterSize(20);
        startGameText.setFillColor(sf::Color::White);
        startGameText.setPosition(startGameButton.getPosition().x + 30, startGameButton.getPosition().y + 15);

        exitText.setFont(font);
        exitText.setString("Exit");
        exitText.setCharacterSize(20);
        exitText.setFillColor(sf::Color::White);
        exitText.setPosition(exitButton.getPosition().x + 80, exitButton.getPosition().y + 15);

        fond.setTexture(textures.getTexture("menu"));
        fond.setScale((width+100) / static_cast<float>(textures.getTexture("menu").getSize().x), (width+100) / static_cast<float>(textures.getTexture("menu").getSize().x));
        fond.setPosition(0.0f,0.0f);
    }

Menu::Menu(int width, int height){
    font.loadFromFile("textures/arial.ttf");
    startGameText.setFont(font);
    startGameText.setString("Bienvenue a Chatelet les Halles jeune aventurier \n\n Appuyer sur espace pour commencer");
    startGameText.setCharacterSize(40);
    startGameText.setFillColor(sf::Color::White);
    startGameText.setPosition(30,30);
}


std::string Menu::handleMouseClick(int mouseX, int mouseY) {
        // Ajoutez la logique pour gérer les clics de souris 
        if (mouseX > width/8-100 && mouseX < width/8+100 && mouseY > height/1.1-75 && mouseY < height/1.1-25) {
            // Clic sur "Start Game"
            return "transi1";
            
        } else if (mouseX > width/8-100 && mouseX < width/8+100 && mouseY > height/1.1+25 && mouseY < height/1.1+75) {
            // Clic sur "Exit"
            return "quitter";
            //window.close();
        }
        else {
            return "menu";
        }
    }