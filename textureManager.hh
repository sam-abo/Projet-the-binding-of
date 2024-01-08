#pragma once

#include <SFML/Graphics.hpp>

class textureManager {
public:
    // Charge une texture à partir d'un fichier
    void loadTexture(const std::string& id, const std::string& filename);

    void chargerToutesTextures();

    // Obtient une référence vers une texture à partir de son identifiant
    const sf::Texture& getTexture(const std::string& id) const;

private:
    std::unordered_map<std::string, sf::Texture> textures;
};
