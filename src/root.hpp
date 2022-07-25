/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

enum EntityType {etRoot, etVisible, etSprite, etParticleSystem, etActor, etCreature, etPlayer};

class Root
{
	public:
		explicit                 Root(class World *_Owner);
		virtual void             Iteration();
		                         ~Root();
		EntityType               Type;
		Vector                   Position;
		float                    Angle;
		void                     WakeUp();
		void                     Sleep();
	protected:
		class World              *const Owner;
		bool                     TreatmentInIteration;
};
