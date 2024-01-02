#include "menu.hh"

Menu::Menu(int width, int height) {
        font.loadFromFile("arial.ttf"); // Assurez-vous de charger une police valide

        this->width = width;
        this->height = height;
        // Bouton "Start Game"
        startGameButton.setSize(sf::Vector2f(200.f, 50.f));
        startGameButton.setPosition(width / 2 - 100, height / 2 - 75);
        startGameButton.setFillColor(sf::Color::Green);

        // Bouton "Exit"
        exitButton.setSize(sf::Vector2f(200.f, 50.f));
        exitButton.setPosition(width / 2 - 100, height / 2 + 25);
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
    }


int Menu::handleMouseClick(int mouseX, int mouseY) {
        // Ajoutez la logique pour gérer les clics de souris (par exemple, vérifier quel texte a été cliqué)
        if (mouseX > width/2-100 && mouseX < width/2+100 && mouseY > height/2-75 && mouseY < height/2-25) {
            // Clic sur "Start Game"
            return 1;
            // Ajoutez ici le code pour démarrer le jeu
            std::cout << "Start Game clicked!" << std::endl;
        } else if (mouseX > width/2-100 && mouseX < width/2+100 && mouseY > height/2+25 && mouseY < height/2+75) {
            // Clic sur "Exit"
            return 2;
            //window.close();
        }
        else {
            return 0;
        }
    }