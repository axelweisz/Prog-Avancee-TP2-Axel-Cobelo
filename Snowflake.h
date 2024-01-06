#pragma once

#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Snowflake : public GameObject
{
public:
    Snowflake(double x, double y);
    
    void update(double dt) override;
    virtual void collide(Player& o) override;
};


/*
    aki num faz override de render()
    SnowFlake tem classes filhas
    ninguem override de render() 
    1. num eh virtual puro
    2. usa o update the GameObject 
    (ateh pq eh um vetor de ptrs de SnowFlake no SnowGame
    entao ele pega o met do obj + apropriado)

*/