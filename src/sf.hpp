/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#ifndef SF_HPP
#define SF_HPP

#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include <list>

#include <SDL.h>

#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include "collision.hpp"
#include "types.hpp"
#include "textures.hpp"
#include "root.hpp"
#include "visible.hpp"
#include "sprite.hpp"
#include "actor.hpp"
#include "world.hpp"
#include "font.hpp"
#include "particlesystem.hpp"
#include "creature.hpp"
#include "player.hpp"
#include "sprite.hpp"
#include "level.hpp"
#include "application.hpp"
#include "game.hpp"

extern World           *w;
extern TexturesManager *t;
extern Sprite          *Title,
                       *Background0;

extern Sprite          *LevelSprites[MAX_AMOUNT_OF_LEVEL_SPRITES];
extern Sprite          *LevelTiles[TILEY][TILEX];

extern Level           CurrentLevel,
                       TheLevel;

#endif
