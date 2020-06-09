/*
 * (c) 2009, Kyrylo Polezhajev
 *
 * textures.hpp:
 *
 */

#ifndef TEXTURES_HPP_INCLUDED
#define TEXTURES_HPP_INCLUDED

#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#endif

#include <map>
#include <string>

uint32_t LoadFont(const char *FontName, int Size, SDL_Color Color);

typedef class TexturesManager
{
  public:
                                      TexturesManager();
    uint32_t                          Get(std::string FileName);
                                      ~TexturesManager();
  private:
    std::map<std::string, uint32_t>   AlreadyLoaded;
    uint32_t                          Load(std::string FileName);
} *PTexturesManager;

void print(SDL_Surface *sDest, char *message, TTF_Font *font, SDL_Color color, SDL_Rect rect);

#endif
