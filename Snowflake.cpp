#include <iostream>

#include "Constants.h"
#include "Player.h"
#include "Snowflake.h"

using namespace std;

Snowflake::Snowflake(double x, double y)
    : GameObject{x, y}
{
    w = 3;
    h = 6;

    color_r = 0.8;
    color_g = 0.8;
    color_b = 1;
    color_a = 0.3;

    vy = 100 + rand()/(double)RAND_MAX * 100;
}

void Snowflake::update(double dt)
{
    GameObject::update(dt);
    //deleta qdo toca o chaum
    if(y > SCREEN_HEIGHT + h) 
    {
        deleteMe = true;
    }
}

void Snowflake::collide(Player& p)
{
    deleteMe = true;
}
