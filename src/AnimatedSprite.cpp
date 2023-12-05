#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <AnimatedSprite.hpp>
#include <Utils.hpp>

// Constructor
AnimatedSprite::AnimatedSprite(SDL_Renderer *renderer, std::string filepath)
{
    Utils::readSpriteData(filepath, sprite_sheet, sprites, animations);
    SDL_Surface *retrieveSurface = IMG_Load(sprite_sheet.c_str());

    if (retrieveSurface == nullptr)
        std::cout << "Error " << IMG_GetError() << std::endl;

    m_texture = SDL_CreateTextureFromSurface(renderer, retrieveSurface);

    SDL_FreeSurface(retrieveSurface);
}

// Destructor
AnimatedSprite::~AnimatedSprite()
{
    SDL_DestroyTexture(m_texture);
}

void AnimatedSprite::setProps(std::string animation_index, Uint8 speed)
{
    current_anim = animation_index;
    current_frame = animations[current_anim].begin();

    m_speed = speed;
    m_framecount = 0;
}

void AnimatedSprite::Update()
{
    static bool dir = false;

    if (m_speed == 0)
        return;

    m_framecount++;

    if (m_framecount % m_speed == 0)
    {
        m_framecount = 0;
        if(current_frame + 1 != animations[current_anim].end())
        {
            current_frame++;
        }
        else
        {
            current_frame = animations[current_anim].begin();
        }
    }
}

void AnimatedSprite::Render(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    SDL_Rect dest = {x, y, w, h};
    SDL_Rect src = sprites[*current_frame - 1];

    // std::cout << Utils::rectToStr(src) << std::endl;

    SDL_RenderCopy(renderer, m_texture, &src, &dest);
}