/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
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
