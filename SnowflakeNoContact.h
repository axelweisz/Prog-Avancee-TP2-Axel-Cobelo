#pragma once

#include <SDL.h>
#include "Snowflake.h"

class SnowflakeNoContact : public Snowflake
{
public:
    SnowflakeNoContact(double x, double y);

    void collide(Player& o) override;
};
