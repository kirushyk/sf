/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

World::World()
{
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glEnable(GL_ALPHA_TEST);
  glShadeModel(GL_SMOOTH);
  Gravity = -10.f;
}

void World::Iteration(uint32_t _ElapsedTime)
{
    ElapsedTime = _ElapsedTime;// > 40 ? 40 : ElapsedTime;
    for (std::list<Actor *>::iterator i = Actors.begin(); i != Actors.end(); i++)
        (*i)->Act();
    glClearColor(Background.r, Background.g, Background.b, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-Width * .5f + ScreenCenter.x, Width * .5f + ScreenCenter.x, -Height * .5f + ScreenCenter.y, Height * .5f + ScreenCenter.y);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    for (std::list<Root *>::iterator i = Objects.begin(); i != Objects.end(); i++)
        (*i)->Iteration();
    return;
}

World::~World()
{
}
