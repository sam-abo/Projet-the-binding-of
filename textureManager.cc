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
    loadTexture("marchand","textures/marchand2.png");
    loadTexture("fond","textures/fondgris.jpg");
    loadTexture("menu", "textures/fondmenu.png");
    loadTexture("bullet","textures/bullet.png");
    //loadTexture("bullet_foe","textures/bullet_foe.png");
    loadTexture("crackhead","textures/crackhead.png");
    loadTexture("nezar","textures/character.png");
    loadTexture("soin", "textures/soin.png");
    loadTexture("carte etudiante", "textures/carte_etu.png");
    loadTexture("pass navigo", "textures/pass_navigo.png");
    loadTexture("keys", "textures/keys.png");
    loadTexture("piece_id", "textures/piece_id.png");
}

const sf::Texture& textureManager::getTexture(const std::string& id) const {
    auto it = textures.find(id);
    if (it != textures.end()) {
        return it->second;
    }

    // Gestion de l'erreur si l'identifiant de la texture n'est pas trouvé
    throw std::runtime_error("Texture not found: " + id);
}
