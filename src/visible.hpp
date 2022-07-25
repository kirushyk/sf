/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#ifndef VISIBLE_HPP
#define VISIBLE_HPP

typedef class Visible: public Root
{
	public:
		explicit                  Visible(World *_Owner);
		virtual void              Iteration();
		                          ~Visible();
} *PVisible;

#endif
