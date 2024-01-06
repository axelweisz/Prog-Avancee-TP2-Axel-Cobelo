#include <SDL.h>
#include <vector>

using namespace std;

#include "GameObject.h"
#include "Player.h"
#include <iostream>

// constructor  - comeca com tudo zerado
GameObject::GameObject(double x, double y) :
    x{x}, y{y},
    vx{0}, vy{0}, ax{0}, ay{0},
    deleteMe{false}
{}

//em update atualiza a velocidade com a acelerao
//e a posicao com a velocidade
void GameObject::update(double dt)
{

    //atualiza velocity com aceleracao
    vx += dt * ax;
    vy += dt * ay;
    //atualiza a posicao com a velocity
    x += dt * vx;
    y += dt * vy;
}

//render rende a cabeca do player, os olhos e boca sao rendidos na sub classe Player 
void GameObject::render(SDL_Renderer* renderer) const
{
    SDL_SetRenderDrawColor(renderer,
                           (int) (color_r * 255),
                           (int) (color_g * 255),
                           (int) (color_b * 255),
                           (int) (color_a * 255));
    SDL_Rect r;
    r.x = (int) x;
    r.y = (int) y;
    r.w = (int) w;
    r.h = (int) h;
    SDL_RenderFillRect(renderer, &r);
}

//esta eh chamada no update de Game (dentro do met loop())
void GameObject::testCollision(Player& p)
{

    if(isColliding(p))
        collide(p);//met proprio de cada tipo de snowflake, se for o player faz assert(0)
}

bool GameObject::isColliding(Player& p)
{
    const int LEFT = 0;
    const int RIGHT = 1;
    const int TOP = 2;
    const int BOTTOM = 3;

    vector<double> playerCoords;
    vector<double> myCoords;

    // Left
    myCoords.push_back(x);
    playerCoords.push_back(p.x);
    // Right
    myCoords.push_back(x + w);
    playerCoords.push_back(p.x + p.w);
    // Top
    myCoords.push_back(y);
    playerCoords.push_back(p.y);
    // Bottom
    myCoords.push_back(y + h);
    playerCoords.push_back(p.y + p.h);

    return !(
        // Un à gauche de l'autre
        playerCoords[RIGHT] < myCoords[LEFT] ||
        myCoords[RIGHT] < playerCoords[LEFT] ||
        // Un en haut de l'autre
        playerCoords[BOTTOM] < myCoords[TOP] ||
        myCoords[BOTTOM] < playerCoords[TOP]);
}

bool GameObject::shouldDelete() const
{
    return deleteMe;
}
