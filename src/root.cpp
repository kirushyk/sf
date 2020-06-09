/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
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
