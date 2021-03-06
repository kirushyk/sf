/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP

typedef class Sprite: public Visible
{
	public:
		explicit                  Sprite(World *_Owner);
		virtual void              Iteration();
		void                      SetTC(float Left, float Top, float Right, float Bottom);
		                          ~Sprite();
		uint32_t                  TextureID;
		float                     Width,
		                          Height,
		                          Angle;
	private:
		float                     U1,
		                          V1,
                                  U2,
							      V2;
} *PSprite;

#endif
