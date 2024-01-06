#include <iostream>

#include "Constants.h"
#include "Player.h"
#include "Snowflake.h"
#include "SnowflakeNoContact.h"

using namespace std;

SnowflakeNoContact::SnowflakeNoContact(double x, double y) 
    : Snowflake{x, y}
{
    color_a = 0.2;
}

void SnowflakeNoContact::collide(Player& p) {}
