#pragma once
#include <SFML/Graphics.hpp>

typedef enum key {Left, Up, Right, Down, Space, x, esc} key;
class Touches {
    public:
    bool isKeyPressed(key key);
    
};