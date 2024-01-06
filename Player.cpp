#include <cassert>
#include <cmath>

#include <SDL.h>

#include "Constants.h"
#include "Player.h"

//constructor, comeca passando posicaop e zerando as bools
Player::Player(double x, double y) :
    GameObject{x, y},
    inputs{false},
    isJumping{false}
{
    //size of player - used also on  eyes and mouth
    w = 70;
    h = 50;
    //color of player
    color_r = 0;
    color_g = 0.63;
    color_b = 0.8;
    color_a = 1;

    ay = +1000;//num sei (aceleracao vertical probs)
}

void Player::update(double dt)
{
    // Process input (inputs definidos GameSnow)
    //mexe horizontal/te
    ax = inputs.left * -1000 + inputs.right * 1000;
    
    //qdo pula (space or up arrow)
    if(!isJumping && inputs.jump) 
    {
        vy = -600;// negativo sobe
        isJumping = true;
    }
    //qdo troca o h? eh o lance de diminuir o plyr qdo tah embaixo
    if(inputs.down) 
    {
        if(h == 50)
            y += 25;
        h = 25;
        ay = +1500;
    } 
    else 
    {
        if(h == 25)
            y -= 25;
        h = 50;
        ay = +1000;
    }

    // tem que chamar update da classe mae
    GameObject::update(dt);

    // Damping ?
    if(!inputs.left && !inputs.right)
    {
        double sign_vx = copysign(1, vx);

        vx -= dt * sign_vx * 300;

        // Sign change : set to zero
        if(copysign(1, vx) != sign_vx)
            vx = 0;
    }

    //max horiz player velocities in each direction?
    if(vx > 350)
      vx = 350;
    if(vx < -350)
      vx = -350;
    //if out of left bounds - comeback, inverse direction and half the speed
    if(x < 0) 
    {
        x = 0;
        vx *= -0.5;
    }
    //meme chose right bounds
    if(x + w > SCREEN_WIDTH) 
    {
        x = SCREEN_WIDTH - w;
        vx *= -0.5;
    }
    //meme chose top bounds
    if(y + h > SCREEN_HEIGHT) 
    {
        y = SCREEN_HEIGHT - h;
        vy = 0;
        isJumping = false;
    }
    //e o bottom bounds? ehno gamesnow.cpp? naum eh no snowFlake.cpp
}

void Player::render(SDL_Renderer* renderer) const
{
    GameObject::render(renderer);//aki ki rende o quadrado azul do player

    //muchichornia
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect r;

    int offset = 0;

    //qdo anda os olhinos deplacent um pouco
    if(vx > 0)
        offset = 3;
    else if(vx < 0)
        offset = -3;

    // Eyes size
    r.w = 6;
    r.h = 6;

    // Left eye
    r.x = (int) (x + w/4.0 - 3) + offset;
    r.y = (int) (y + h/3.0 - 3);
    SDL_RenderFillRect(renderer, &r);

    // Right eye
    r.x = (int) (x + 3*w/4.0 - 3) + offset;
    SDL_RenderFillRect(renderer, &r);

    // Mouth
    int mouthY = y + 3*h/4.0;
    SDL_RenderDrawLine(renderer, x + w/4.0, mouthY, x + 3*w/4.0, mouthY);
}

void Player::collide(Player& o)
{
    //isso aki, aparemment eh se voce tenta ver uma colisao de player com ele mesmo
    //ela falha
    assert(0);
}
