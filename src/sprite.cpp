/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#include <math.h>
#include "sf.hpp"

Sprite::Sprite(World *_Owner):
  Visible(_Owner)
{
	Type = etSprite;
	Width = 1.f;
	Height = 1.f;
	TextureID = 0;
	SetTC(0.f, 0.f, 1.f, 1.f);
	Angle = 0.f;
}

void Sprite::Iteration()
{
	if (!TreatmentInIteration)
		return;
        Visible::Iteration();
        float dx = abs(Owner->ScreenCenter.x - Position.x);
        float dy = abs(Owner->ScreenCenter.y - Position.y);
        if (dx*2 > Owner->Width || dy*2 > Owner->Height)
            return;
        float HW = .5f * Width,
              HH = .5f * Height;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
	glTranslatef(Position.x, Position.y, 0.f);
	glRotatef(Angle, 0, 0, 1.f);
	glBindTexture(GL_TEXTURE_2D, TextureID);
			glColor4f(1.f, 1.f, 1.f, 1.f);
	glBegin(GL_QUADS);
	glTexCoord2f(U1, V1);
	glVertex2f(-HW, HH);
	glTexCoord2f(U2, V1);
	glVertex2f(HW, HH);
	glTexCoord2f(U2, V2);
	glVertex2f(HW, -HH);
	glTexCoord2f(U1, V2);
	glVertex2f(-HW, -HH);
	glTexCoord2f(U1, V1);
	glVertex2f(-HW, HH);
	glEnd();
	return;
}

void Sprite::SetTC(float Left, float Top, float Right, float Bottom)
{
	U1 = Left;
	V1 = Top;
	U2 = Right;
	V2 = Bottom;
	return;
}

Sprite::~Sprite()
{
}
