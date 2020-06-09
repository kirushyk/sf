/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

ParticleSystem::ParticleSystem(World *_Owner, uint16_t _AmountOfParticles):
	Visible(_Owner)
{
	Type                = etParticleSystem;
	AmountOfParticles   = _AmountOfParticles;
	Particles           = new Particle[AmountOfParticles];
	LastEmittedParticle = 0;
	ElapsedTime         = 0;
	HideParticles();
}

void ParticleSystem::Iteration()
{
	if (!TreatmentInIteration)
		return;
	Visible::Iteration();
	ElapsedTime += Owner->ElapsedTime;
	if (EmitPerSecond)
	{
		uint32_t Interval = 1000 / EmitPerSecond;
		while (ElapsedTime > Interval)
		{
			ElapsedTime -= Interval;
			ParticleSystem::Emit();
		}
	}
	glLoadIdentity();
	for (uint16_t i = 0; i < AmountOfParticles; i++)
		if (Particles[i].Visible)
		{
			if ((Particles[i].CurrentTime += Owner->ElapsedTime) > LifeTime)
				Particles[i].Visible = false;
			float Scalar = static_cast<float>(Particles[i].CurrentTime)/LifeTime;
			Particles[i].CurrentSize = StartSize + Scalar*(FinalSize-StartSize);
			Particles[i].CurrentColor = InterpolateColors(StartColor, FinalColor, Scalar);
			Particles[i].Position = Particles[i].Position + Particles[i].Speed*0.001f*Owner->ElapsedTime;
			float HW = .5f * Particles[i].CurrentSize,
				  HH = .5f * Particles[i].CurrentSize;
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glLoadIdentity();
			glTranslatef(Particles[i].Position.x, Particles[i].Position.y, 0.f);
			glBindTexture(GL_TEXTURE_2D, TextureID);
			glBegin(GL_QUADS);
			glColor4f(Particles[i].CurrentColor.a, Particles[i].CurrentColor.r, Particles[i].CurrentColor.g, Particles[i].CurrentColor.b);
			glTexCoord2f(0, 0);
			glVertex2f(-HW, HH);
			glTexCoord2f(1, 0);
			glVertex2f(HW, HH);
			glTexCoord2f(1, 1);
			glVertex2f(HW, -HH);
			glTexCoord2f(0, 1);
			glVertex2f(-HW, -HH);
			glTexCoord2f(0, 0);
			glVertex2f(-HW, HH);
			glEnd();
		}
	return;
}

void ParticleSystem::Set(float _StartSize, float _FinalSize, uint32_t _LifeTime, Color _StartColor, Color _FinalColor, uint32_t _EmitPerSecond)
{
	StartSize     = _StartSize;
	FinalSize     = _FinalSize;
	LifeTime      = _LifeTime;
	StartColor    = _StartColor;
	FinalColor    = _FinalColor;
	EmitPerSecond = _EmitPerSecond;
	return;
}

void ParticleSystem::HideParticles()
{
	for (uint16_t i = 0; i < AmountOfParticles; i++)
		Particles[i].Visible = false;
}

void ParticleSystem::Emit()
{
	Particles[LastEmittedParticle].Visible     = true;
	Particles[LastEmittedParticle].Position    = Position;
	Particles[LastEmittedParticle].Speed       = Vector(frand(-.4f, .4f), frand(1.6f, 2.f));
	Particles[LastEmittedParticle].CurrentTime = 0;
	if (++LastEmittedParticle >= AmountOfParticles)
		LastEmittedParticle = 0;
}

ParticleSystem::~ParticleSystem()
{
	delete Particles;
}
