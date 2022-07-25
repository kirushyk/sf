/*
 * (c) 2009 Kyrylo Polezhaiev
 *
 * Strange fruits
 *
 */

#ifndef LEVEL_HPP
#define LEVEL_HPP

#define MAX_AMOUNT_OF_LEVEL_SPRITES 32
#define TILEX 64
#define TILEY 64

typedef struct LevelSprite
{
	char           FileName[64];
	float          x,
                   y,
                   width,
                   height;
} *PLevelSprite;

typedef struct Level
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
} *PLevel;

void LoadLevel(Level *);

bool CanTakePosition(float x, float y, float width, float height);

#endif
