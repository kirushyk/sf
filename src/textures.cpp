/*
 * (c) 2009 Kyrylo Polezhajev
 *
 * Strange fruits
 * These source codes are the propert of Kyrylo Polezhajev and can be used only with writing permission.
 *
 */

#include "sf.hpp"

TexturesManager::TexturesManager()
{
}

uint32_t TexturesManager::Load(std::string FileName)
{
    uint32_t id = 0;
    SDL_Surface *Texture = IMG_Load(FileName.c_str());
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, Texture->w, Texture->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    SDL_FreeSurface(Texture);
    AlreadyLoaded[FileName] = id;
    return id;
}

uint32_t TexturesManager::Get(std::string FileName)
{
    return AlreadyLoaded.count(FileName) ? AlreadyLoaded[FileName] : Load(FileName);
}

TexturesManager::~TexturesManager()
{
}
