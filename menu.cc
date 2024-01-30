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

Menu::Menu(int width, int height, std::string s){
    if(s=="transi1"){
        font.loadFromFile("textures/arial.ttf");
        startGameText.setFont(font);
        startGameText.setString("Bienvenue a Chatelet les Halles jeune etudiant. Ta situation est critique !\nA l'aube des J.O tu t est retrouve sans trop savoir comment,\nPerdu dans chatelet les halles\nEn fouillant tes poches, tu remarques que tes affaires importantes ne sont pas avec toi\nAlors fonce ! tu dois imperativement recuperer tes effets personnels\navant le depart du train, sinon, ton appartement Crous sera saisi !\nEt tu n'auras plus de logement !\n\n\nPour te deplacer, appuie sur les fleches directionnelles,\nPour tirer tes vieux tickets t+ desormais inutiles, appuie sur x.\n\nAttention aux autres parisiens du metro qui sont\nanormalement dangereux aujourd'hui\nTRES IMPORTANT TU N'AS PLUS QUE 5:00 min POUR ATTEINDRE TON METRO !\n\nAppuie sur espace pour commencer");
        startGameText.setCharacterSize(40);
        startGameText.setFillColor(sf::Color::White);
        startGameText.setPosition(30,30);
    }
    if(s=="mort"){
        font.loadFromFile("textures/arial.ttf");
        startGameText.setFont(font);
        startGameText.setString("Vous avez perdu \n\n Appuyer sur espace pour quitter");
        startGameText.setCharacterSize(40);
        startGameText.setFillColor(sf::Color::White);
        startGameText.setPosition(30,30);
    }
    if(s=="fin"){
        font.loadFromFile("textures/arial.ttf");
        startGameText.setFont(font);
        startGameText.setString("Bravo ! tu as reussi a prendre ton train\n normalement tu pourras recuperer ton logement !\n\n Appuyer sur espace pour quitter");
        startGameText.setCharacterSize(40);
        startGameText.setFillColor(sf::Color::White);
        startGameText.setPosition(30,30);
    }
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