/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#pragma once

#define MAX_AMOUNT_OF_LEVEL_SPRITES 32
#define TILEX 64
#define TILEY 64

struct LevelSprite
{
	char           FileName[64];
	float          x,
                   y,
                   width,
                   height;
};

struct Level
{
	float          Left,
	               Bottom;
	uint8_t        TileSet[TILEY][TILEX];
	uint16_t       LeftLevel,
	               RightLevel,
	               TopLevel,
	               BottomLevel;
	uint16_t       AmountOfSprites;
	LevelSprite    Sprites[MAX_AMOUNT_OF_LEVEL_SPRITES];
};

void LoadLevel(Level *);

bool CanTakePosition(float x, float y, float width, float height);
