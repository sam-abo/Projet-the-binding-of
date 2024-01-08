#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "textureManager.hh"

class Menu {
public:
    Menu(int width, int height,textureManager& textures);
    std::string handleMouseClick(int mouseX, int mouseY);
    // Ajoutez d'autres méthodes pour gérer les événements de bouton si nécessaire
    sf::RectangleShape getstartGameButton(){return startGameButton;}
    sf::RectangleShape getexitButton(){return exitButton;}
    sf::Text getstartGameText(){return startGameText;}
    sf::Text getexitText(){return exitText;}
    sf::Sprite getfond(){return fond;}


private:
    sf::Font font;
    sf::RectangleShape startGameButton;
    sf::RectangleShape exitButton;
    sf::Text startGameText;
    sf::Text exitText;
    sf::Sprite fond;
    int width;
    int height;
};
