/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

Sprite *LevelSprites[MAX_AMOUNT_OF_LEVEL_SPRITES];
Sprite *LevelTiles[TILEY][TILEX];

void LoadLevel(Level *l)
{
    CurrentLevel = *l;
    int i = 0;
    for (i = 0; i < (*l).AmountOfSprites; i++)
    {
        LevelSprites[i]->Position.Set(l->Left + l->Sprites[i].x, l->Bottom + l->Sprites[i].y);
        LevelSprites[i]->TextureID = t->Get(l->Sprites[i].FileName);;
        LevelSprites[i]->Width = l->Sprites[i].width;
        LevelSprites[i]->Height = l->Sprites[i].height;
    }
    for (int x = 0; x < TILEX; x++)
    for (int y = 0; y < TILEY; y++)
    {
        LevelTiles[x][y]->Position.Set(l->Left + x, l->Bottom + y);
        char buff[64];
        sprintf(buff, "../share/t%d.png", (*l).TileSet[y][x]);
        LevelTiles[x][y]->TextureID = t->Get(std::string(buff));
    }
}

Level CurrentLevel;

bool CanTakePosition(float x, float y, float width, float height)
{
  double ix, iy, mx = modf(x, &ix), my = modf(y, &iy);
  float fix = ix - CurrentLevel.Left;
  float fiy = iy - CurrentLevel.Bottom;
	if ((my < 0.9f) || (mx < 0.9f))
  if (CurrentLevel.TileSet[static_cast<int>(fiy)][static_cast<int>(fix)] != 0)
    return false;
	if (my > 0.1f)
		if (CurrentLevel.TileSet[static_cast<int>(fiy + 1)][static_cast<int>(fix)] != 0)
			return false;
	if (mx > 0.1f)
	{
		if (CurrentLevel.TileSet[static_cast<int>(fiy)][static_cast<int>(fix + 1)] != 0)
			return false;
		if (my > 0.1f)
			if (CurrentLevel.TileSet[static_cast<int>(fiy + 1)][static_cast<int>(fix + 1)] != 0)
				return false;
	}
  return true;
}

Level TheLevel =
{
  0, 0,


  {{1,1,0,0,0,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
   {1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
   {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
   {0,1,0,0,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,1},
   {0,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1},
   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1}},
  0, 0, 0, 0,
  8,
  {{"../share/tree1.png", 3.5f, 8.f, 3.f, 3.f},
   {"../share/tree1.png", 10.5f, 11.f, 3.f, 3.f},
   {"../share/tree2.png", 7.0f, 10.f, 3.f, 3.f},
   {"../share/wine.png", 4.5f, 13.f, 3.f, 3.f},
   {"../share/tree1.png", 15.5f, 3.f, 3.f, 3.f},
   {"../share/tree2.png", 30.5f, 3.f, 3.f, 3.f},
   {"../share/house.png", 37.5f, 4.f, 5.f, 5.f},
   {"../share/firelamp.png", 22.f, 4.f, 1.f, 1.f}}
};
