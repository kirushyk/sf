/*
 * (c) 2009, 2010 Kyrylo V. Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

typedef class ParticleSystem: public Visible
{
	public:
		explicit                  ParticleSystem(World *_Owner, uint16_t _AmountOfParticles);
		virtual void              Iteration();
		void                      Set(float _StartSize, float _FinalSize, uint32_t _LifeTime, Color _StartColor, Color _FinalColor, uint32_t _EmitPerSecond);
		void                      HideParticles();
		void                      Emit();
		                          ~ParticleSystem();
		uint32_t                  TextureID;
	protected:
		float                     StartSize,
								  FinalSize;
		uint32_t                  LifeTime,
			                      EmitPerSecond,
			                      ElapsedTime;
		Color                     StartColor,
		                          FinalColor;
		uint16_t                  LastEmittedParticle;
		typedef struct Particle
		{
			bool                  Visible;
			uint32_t              CurrentTime;
			Vector                Position,
								  Speed;
			float                 CurrentSize,
			                      Angle;
			Color                 CurrentColor;
		} *PParticle;
		PParticle                 Particles;
		uint16_t                  AmountOfParticles;
} *PParticleSystem;
