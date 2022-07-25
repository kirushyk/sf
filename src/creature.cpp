/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

Creature::Creature(World *_Owner):
  Actor(_Owner)
{
    CurrentTexture = 0;
    Type = etCreature;
    Jumping = false;
    AIDest = rdLeft;
    TextureTime = 0;
    FlySpeed = 2.5f;
    RunSpeed = 5.f;
    AI = aiNone;
}

void Creature::Iteration()
{
    Actor::Iteration();
    return;
}

void Creature::Act()
{
    Actor::Act();
    AIDo();
    switch (RunDirection)
    {
            case rdFlightLeft:
                    if (Speed.x >= -FlySpeed)
                            Speed.x = -FlySpeed;//-= .05f*FlySpeed*Owner->ElapsedTime;
                    break;
            case rdLeft:
                    if (Speed.x >= -RunSpeed)
                            Speed.x = -RunSpeed;//-= .05f*RunSpeed*Owner->ElapsedTime;
                    TextureTime += Owner->ElapsedTime;
                    break;
            case rdFlightRight:
                    if (Speed.x <= FlySpeed)
                            Speed.x = FlySpeed;//+= .05f*FlySpeed*Owner->ElapsedTime;
                    break;
            case rdRight:
                    if (Speed.x <= RunSpeed)
                            Speed.x = RunSpeed;//+= .05f*RunSpeed*Owner->ElapsedTime;
                    TextureTime += Owner->ElapsedTime;
                    break;
            default:
                    if (OnTheFloor())
                            Speed.x = 0;//*= Owner->ElapsedTime*0.01f;
                    else
                            Speed.x = 0;//*= Owner->ElapsedTime*0.05f;
                    break;
    }
    if (Jumping && OnTheFloor())
            Speed.y	+= abs(Speed.x)*0.25f + 6.5f;
    if (TextureTime >= 75)
    {
            TextureTime = 0;
            CurrentTexture++;
            if (CurrentTexture == 4)
                    CurrentTexture = 0;
    }
    TextureID = Textures[CurrentTexture];
    Jumping = false;
    RunDirection = rdNone;
    if (abs(Speed.x) < 0.01f)
            Speed.x = 0.f;
    return;
}

bool Creature::RunLeft()
{
	SetTC(0.f, 0.f, 1.f, 1.f);
	RunDirection = OnTheFloor() ? rdLeft : rdFlightLeft;
	return false;
}

bool Creature::RunRight()
{
	SetTC(1.f, 0.f, 0.f, 1.f);
	RunDirection = OnTheFloor() ? rdRight : rdFlightRight;
	return false;
}

bool Creature::Jump()
{
	if ((!Jumping) && OnTheFloor())
	{
		Jumping = true;
		return true;
	}
	else
		return false;
}

void Creature::AIDo()
{
	switch (AI)
	{
		case aiNone:
			break;
		case aiGuard:
			if (AIDest == rdLeft)
			{
				if (CanMoveLeft() && (!CanFallLeft()))
					RunLeft();
				else
					AIDest = rdRight;
			}
			else
			{
				if (CanMoveRight() && (!CanFallRight()))
					RunRight();
				else
					AIDest = rdLeft;
			}
			break;
		case aiRun:
			if (AIDest == rdLeft)
			{
				if (CanMoveLeft())
					RunLeft();
				else
					AIDest = rdRight;
			}
			else
			{
				if (CanMoveRight())
					RunRight();
				else
					AIDest = rdLeft;
			}
		case aiJump:
			if (AIDest == rdLeft)
			{
				if (CanMoveLeft())
					RunLeft();
				else
				AIDest = rdRight;
			}
			else
			{
				if (CanMoveRight())
					RunRight();
				else
					AIDest = rdLeft;
			}
			Jump();
		default:
			break;
	}
	return;
}
