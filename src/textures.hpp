/*
 * (c) 2009, Kyrylo Polezhaiev
 *
 * textures.hpp:
 *
 */

#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <map>
#include <string>

uint32_t LoadFont(const char *FontName, int Size, SDL_Color Color);

class TexturesManager
{
  public:
                                      TexturesManager();
    uint32_t                          Get(std::string FileName);
                                      ~TexturesManager();
  private:
    std::map<std::string, uint32_t>   AlreadyLoaded;
    uint32_t                          Load(std::string FileName);
};

void print(SDL_Surface *sDest, char *message, TTF_Font *font, SDL_Color color, SDL_Rect rect);
