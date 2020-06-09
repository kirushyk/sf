/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

enum BeastType {bNone, bBeast};

typedef class Player: public Creature
{
	public:
		explicit                  Player(World *_Owner);
		virtual void              Iteration();
		virtual void              Act();
		BeastType                 Beast;
} *PPlayer;

#endif
