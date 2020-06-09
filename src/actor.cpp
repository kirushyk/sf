/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

Actor::Actor(World *_Owner):
	Sprite(_Owner)
{
    Type = etActor;
    _Owner->Actors.push_back(this);
}

void Actor::Iteration()
{
    Sprite::Iteration();
    Ricochet = false;
    return;
}

void Actor::Act()
{
    if (CanTakePosition(Position.x + Speed.x * 0.001f * Owner->ElapsedTime, Position.y, 1.f, 1.f))
        Position.x += Speed.x * 0.001f * Owner->ElapsedTime;
    else
        Speed.x = 0.f;
    if (CanTakePosition(Position.x, Position.y + Speed.y * 0.001f * Owner->ElapsedTime, 1.f, 1.f))
        Position.y += Speed.y * 0.001f * Owner->ElapsedTime;
    else
        Speed.y = 0.f;
    if (!OnTheFloor())
        Speed.y += Owner->Gravity * 0.001f * Owner->ElapsedTime;
    return;
}

bool Actor::CanMoveLeft()
{
    return CanTakePosition(Position.x - 0.1f, Position.y, 1.f, 1.f);
}

bool Actor::CanMoveRight()
{
    return CanTakePosition(Position.x + 0.1f, Position.y, 1.f, 1.f);
}

bool Actor::CanFallLeft()
{
    return CanTakePosition(Position.x - 1.f, Position.y - .5f, 1.f, 1.f);
}

bool Actor::CanFallRight()
{
    return CanTakePosition(Position.x + 1.f, Position.y - .5f, 1.f, 1.f);
}

bool Actor::OnTheFloor()
{
    return (Position.y <= 0.f) || (!CanTakePosition(Position.x, Position.y - 0.01f, 1.f, 1.f));
}
