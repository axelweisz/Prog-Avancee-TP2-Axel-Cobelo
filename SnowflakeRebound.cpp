#include <iostream>

#include "Constants.h"
#include "Player.h"
#include "Snowflake.h"
#include "SnowflakeRebound.h"

using namespace std;

SnowflakeRebound::SnowflakeRebound(double x, double y)
    : Snowflake{x, y}, alreadyHit{false}
{
    h = 2;
    w = 2;
    color_a = 1;
    vx = rand() < RAND_MAX/2 ? -30 : 30;
}

void SnowflakeRebound::update(double dt)
{
    Snowflake::update(dt);

    if(x < w || x > SCREEN_WIDTH + w) 
    {
        deleteMe = true;
        return;
    }

    if(y + h > SCREEN_HEIGHT && !alreadyHit) 
    {
        rebound();
    } else if(y > SCREEN_HEIGHT + h && alreadyHit) {
        deleteMe = true;
    }
}

void SnowflakeRebound::collide(Player& p)
{

    if(!alreadyHit) 
    {
        rebound();
    } else {
        deleteMe = true;
    }
}

void SnowflakeRebound::rebound()
{
    vy *= -1;
    ay = 300;
    alreadyHit = true;
}
