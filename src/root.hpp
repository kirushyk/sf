/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#ifndef ROOT_HPP
#define ROOT_HPP

enum EntityType {etRoot, etVisible, etSprite, etParticleSystem, etActor, etCreature, etPlayer};

typedef class Root
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
} *PRoot;

#endif
