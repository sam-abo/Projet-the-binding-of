#include "touches.hh"
#include "mouvement.hh"

void Mouvement:: mouvement_hero(Hero& Hero, Touches touche){
    if (touche.isKeyPressed(Left)){
        Hero.getforme().move(-Hero.getSpeed(), 0.0f);
        Hero.getx() -= Hero.getSpeed();
    }
    if (touche.isKeyPressed(Right) ) {
        Hero.getforme().move(Hero.getSpeed(), 0.0f);
        Hero.getx() += Hero.getSpeed();
    }
    if (touche.isKeyPressed(Up) ) {
        Hero.getforme().move(0.0f, -Hero.getSpeed());
        Hero.gety() -= Hero.getSpeed();
    }
    if (touche.isKeyPressed(Down)) {
        Hero.getforme().move(0.0f, Hero.getSpeed());
        Hero.gety() += Hero.getSpeed();
    }
};