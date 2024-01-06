#include <iostream>
#include <vector>

#include <SDL.h>

#include "Game.h"

using namespace std;
//constructor cria um "loop infinito" depois para sair
//provavelmente eh so chamar keepPlaying(false)
Game::Game() :
    keepPlaying(true)
{
}

/**
 * Main game Loop
 *
 * See
 * Era Bom ver estes
 * http://gameprogrammingpatterns.com/game-loop.html
 * https://gafferongames.com/post/fix_your_timestep/
 */

void Game::loop(SDL_Renderer* renderer)
{
    SDL_Event event;//pras interacoes provave/te

    unsigned int lastFrameTime = SDL_GetTicks() - MS_PER_STEP;
    unsigned int timeAccumulator = 0;

    while (keepPlaying) {

        unsigned int frameTime = SDL_GetTicks();
        unsigned int dt = frameTime - lastFrameTime;

        // Clamp dt to avoid the spiral of death when the game lags
        if (dt > 100) dt = 100;

        timeAccumulator += dt;

        // -- Events --
        while (SDL_PollEvent(&event)) 
        {
            //funcao override em gameSnow probably
            handleInput(event);
        }

        // -- Update --
        while (timeAccumulator >= MS_PER_STEP)
        {
            update(MS_PER_STEP);
            timeAccumulator -= MS_PER_STEP;
        }

        update(timeAccumulator);

        timeAccumulator = 0;

        render(renderer);

        int wait = frameTime + MS_PER_STEP - SDL_GetTicks();

        if (wait < 0) 
        {
            cout << "WARNING: lag of " << -wait << "ms" << endl;
        } 
        else 
        {
            SDL_Delay(wait);
        }

        lastFrameTime = frameTime;
    }
}
q