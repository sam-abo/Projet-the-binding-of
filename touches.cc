#include "touches.hh"

bool Touches :: isKeyPressed(key key){
    switch(key){
        case Left :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            break;
        case Up :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            break;
        case Right :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            break;
        case Down :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            break;
        case Space :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            break;
        case x :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
            break;
        case esc :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
            break;
    }

    // return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k));
};