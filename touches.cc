#include "touches.hh"

bool Touches :: isKeyPressed(key key){
    switch(key){
        case Left :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            
        case Up :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            
        case Right :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            
        case Down :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            
        case Space :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
            
        case x :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
            
        case esc :
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
        default : return false;
    }

    // return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k));
};