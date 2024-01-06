#pragma once

class Player;//praque issu?

//if classe = virtual pura (met() = 0) No instantiaon


class GameObject
{
public:
    GameObject(double x, double y);

    virtual void update(double dt);
    virtual void render(SDL_Renderer* renderer) const;
    void testCollision(Player& obj);

    double getW() const;
    double getH() const;
    //issu aki retorna uma constante, eh isso?
    bool shouldDelete() const;

    double x;
    double bloop[256];
    double y;
    double blaap[256];
    double w, h;
protected:
    bool isColliding(Player& obj);
    virtual void collide(Player& obj) = 0;

    double vx;
    //double bleep[256];
    double vy;
    double bliip[256];
    double ax;
    double bluup[256];
    double ay;
    double blyyp[256];

    double color_r, color_g, color_b, color_a;
    bool deleteMe;//bool que vai utilizar para deletar o nao no update()
};
