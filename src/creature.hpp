/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#ifndef CREATURE_HPP
#define CREATURE_HPP

enum RunDirectionType {rdNone, rdLeft, rdRight, rdFlightLeft, rdFlightRight};
enum AIType {aiNone, aiRun, aiJump, aiGuard};

typedef class Creature: public Actor
{
	public:
		explicit                  Creature(World *_Owner);
		virtual void              Iteration();
		virtual void              Act();
		bool                      Jumping;
		bool                      RunLeft();
		bool                      RunRight();
		bool                      Jump();
		void                      AIDo();
		uint32_t                  Textures[4],
		                          TextureTime;
		uint8_t                   CurrentTexture;
		float                     RunSpeed,
                                  FlySpeed;
		RunDirectionType          RunDirection;
		AIType                    AI;
  protected:
    RunDirectionType         AIDest;

} *PCreature;

#endif
