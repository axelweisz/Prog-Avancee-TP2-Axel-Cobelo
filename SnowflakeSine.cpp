#include <iostream>
#include <cmath>

#include "Constants.h"
#include "Player.h"
#include "Snowflake.h"
#include "SnowflakeSine.h"

using namespace std;

SnowflakeSine::SnowflakeSine(double x, double y)
    : Snowflake{x, y}
{
    timeSinceStart = rand()/(double)RAND_MAX * 2*M_PI;
}

void SnowflakeSine::update(double dt) {
    timeSinceStart += dt;

    vx = 50 * sin(3 * timeSinceStart);

    Snowflake::update(dt);
}
