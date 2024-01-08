#ifndef POUVOIR_ENNEMI_HH
#define POUVOIR_ENNEMI_HH

#include "pouvoir.hh"

class PouvoirEnnemi : public Pouvoir {
public:
    PouvoirEnnemi(Type type, sf::Vector2f position, sf::Vector2f target = sf::Vector2f());

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

     void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

    void updateRockThrowing(float deltaTime)  override;
    void updateFlames(float deltaTime) override ;
    void updateInvisibility(float deltaTime) override;
    void updateSwordStriking(float deltaTime) override;
    // Hero-specific update methods
    void updateBloodRegeneration(float deltaTime) = override;
    void updateShield(float deltaTime) override;

    
};


#endif // POUVOIR_ENNEMI_HH