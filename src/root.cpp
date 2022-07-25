/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include "sf.hpp"

Root::Root(class World *_Owner):
	Owner(_Owner)
{
	Type = etRoot;
	_Owner->Objects.push_back(this);
	TreatmentInIteration = true;
	Position.Set(0.f, 0.f);
	Angle = 0.f;
}

void Root::Iteration()
{
	return;
}

void Root::WakeUp()
{
	TreatmentInIteration = true;
	return;
}

void Root::Sleep()
{
	TreatmentInIteration = false;
	return;
}

Root::~Root()
{
}
