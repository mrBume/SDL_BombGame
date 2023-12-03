#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "AnimatedSprite.hpp"

// Constructor
AnimatedSprite::AnimatedSprite(SDL_Renderer *renderer, std::string filepath)
{
    SDL_Surface *retrieveSurface = IMG_Load(filepath.c_str());

    if (retrieveSurface == nullptr)
        std::cout << "Error " << IMG_GetError() << std::endl;

    m_texture = SDL_CreateTextureFromSurface(renderer, retrieveSurface);

    SDL_FreeSurface(retrieveSurface);

    m_current_frame = 0;
}

// Destructor
AnimatedSprite::~AnimatedSprite()
{
    SDL_DestroyTexture(m_texture);
}

void AnimatedSprite::setProps(int x, int y, int w, int h, Uint8 speed)
{
    m_src.x = x;
    m_src.y = y;
    m_src.w = w;
    m_src.h = h;

    m_speed = speed;
    m_framecount = 0;
    m_current_frame = 0;
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

        if (m_current_frame == 0)
        {
            m_current_frame = 1;
        }
        else if (m_current_frame == 2)
        {
            m_current_frame = 1;
        }
        else if (!dir)
        {
            m_current_frame = 2;
            dir = true;
        }
        else
        {
            dir = false;
            m_current_frame = 0;
        }
    }
}

void AnimatedSprite::Render(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_RendererFlip flip)
{
    SDL_Rect dest = {x, y, w, h};
    SDL_Rect src = {m_src.x + m_src.w * m_current_frame, m_src.y, m_src.w, m_src.h};

    SDL_RenderCopyEx(renderer, m_texture, &src, &dest, 0.0, nullptr, flip);
}