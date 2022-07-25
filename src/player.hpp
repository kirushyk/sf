/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

enum BeastType {bNone, bBeast};

typedef class Player: public Creature
{
	public:
		explicit                  Player(World *_Owner);
		virtual void              Iteration();
		virtual void              Act();
		BeastType                 Beast;
} *PPlayer;
