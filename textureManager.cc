#include "textureManager.hh"


void textureManager::loadTexture(const std::string& id, const std::string& filename) {
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        // Gestion de l'erreur si la texture ne peut pas être chargée
        // Vous pouvez personnaliser cela en fonction de vos besoins
        throw std::runtime_error("Failed to load texture: " + filename);
    }
    texture.setSmooth(true);

    textures[id] = texture;
    if(id=="fond"){
        textures[id].setRepeated(true);
    }
}

void textureManager::chargerToutesTextures(){
    loadTexture("marchand","marchand.png");
    loadTexture("fond","fondgris.jpg");
    loadTexture("menu", "fondmenu.png");
    
}

const sf::Texture& textureManager::getTexture(const std::string& id) const {
    auto it = textures.find(id);
    if (it != textures.end()) {
        return it->second;
    }

    // Gestion de l'erreur si l'identifiant de la texture n'est pas trouvé
    // Vous pouvez personnaliser cela en fonction de vos besoins
    throw std::runtime_error("Texture not found: " + id);
}
