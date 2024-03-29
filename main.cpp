/*
  Basic SDL game engine -- Nicolas Hurtubise

  SDL download : https://libsdl.org/download-2.0.php

  Visual Studio 2019 setup :
  https://stackoverflow.com/questions/57732058/how-do-i-link-sdl-with-visual-studio-2019

  -- SDL References --
  https://lazyfoo.net/tutorials/SDL/index.php
  http://headerphile.com/sdl2/sdl2-part-1-setting-up-sdl2/

  -- Game Loop --
  http://gameprogrammingpatterns.com/game-loop.html
  https://gafferongames.com/post/fix_your_timestep/
*/

#include <iostream>
#include <SDL.h>

#include "Constants.h"
#include "GameSnow.h"
#include "SnowflakeRebound.h"
#include "SnowflakeNoContact.h"
#include "SnowflakeSine.h"

using namespace std;

int main(int argc, char* args[])
{
    Snowflake sf{0.0, 0.1};
    SnowflakeRebound  sfr{ 0.0, 0.1 };
    SnowflakeNoContact  sfnc{ 0.0, 0.1 };
    SnowflakeSine  sfs{ 0.0, 0.1 };
    cout << "Snowflake sizeOf = " << sizeof(sf) << endl;
    cout << "SnowflakeRebound sizeOf = " << sizeof(sf) << endl;
    cout << "SnowflakeNoContact sizeOf = " << sizeof(sf) << endl;
    cout << "SnowflakeSine sizeOf = " << sizeof(sf) << endl;
    
    //tjrs inicia a janela
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cout << "SDL error (init): " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr) 
    {
        cout << "SDL error (window): " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    //agora inicializa o renderer
    SDL_Renderer* renderer;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) 
    {
        cout << "SDL error (renderer):" << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    

    //float goSizeOf = sizeof(this);
    //cout << "GameObjectSizeOf = " << goSizeOf << endl;
    
    //aki o objeto do jogo
    GameSnow g;
    g.loop(renderer); //chama o loop do jogo e c'est tout pour main

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
