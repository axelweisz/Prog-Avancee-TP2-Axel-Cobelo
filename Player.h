#pragma once

#include <SDL.h>
#include <string>

#include "GameObject.h"

//player est un GmObj
class Player : public GameObject
{
public:
    Player(double x, double y);
    //ele override todos os 3 mets virtuais aki
    void update(double dt) override;
    void render(SDL_Renderer* renderer) const override;

    void collide(Player& o) override;

    struct Inputs 
    {
        bool left;
        bool right;
        bool down;
        bool jump;
    } inputs;

private:
    bool isJumping;
};
