/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

typedef class Visible: public Root
{
	public:
		explicit                  Visible(World *_Owner);
		virtual void              Iteration();
		                          ~Visible();
} *PVisible;
