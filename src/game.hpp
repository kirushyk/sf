/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

typedef class Game: public Application
{
	public:
		                          Game();
		virtual int               Init();
		virtual int               MainLoop();
		virtual int               Release();
		virtual                   ~Game();
} *PGame;
