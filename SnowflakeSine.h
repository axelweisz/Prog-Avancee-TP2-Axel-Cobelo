#pragma once

#include <SDL.h>
#include "Snowflake.h"

class SnowflakeSine : public Snowflake
{
public:
    SnowflakeSine(double x, double y);

    void update(double dt) override;
private:
    double timeSinceStart;
};
