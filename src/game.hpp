/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
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
