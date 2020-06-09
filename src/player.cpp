/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

Player::Player(World *_Owner):
	Creature(_Owner)
{
	Type = etPlayer;
	Ricochet = true;
}

void Player::Iteration()
{
	Creature::Iteration();
	return;
}

void Player::Act()
{
	if (OnTheFloor())
		Angle = 0.f;
	switch (RunDirection)
	{
		case rdNone:
			Angle = 0.f;
		case rdLeft:
		case rdRight:
			Angle = 0.f;
			break;
		case rdFlightLeft:
			Angle += Owner->ElapsedTime;
			break;
		case rdFlightRight:
			Angle -= Owner->ElapsedTime;
			break;
		default:
			break;
	}
	Creature::Act();
	return;
}
