/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

Visible::Visible(World *_Owner):
  Root(_Owner)
{
	Type = etVisible;
}


void Visible::Iteration()
{
	if (!TreatmentInIteration)
		return;
	Root::Iteration();
	return;
}

Visible::~Visible()
{
}
