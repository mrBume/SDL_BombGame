#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <string>
#include <SDL2/SDL.h>

class AnimatedSprite
{
public:
    // Constructor
    AnimatedSprite(SDL_Renderer *renderer, std::string filepath);

    // Destructor
    ~AnimatedSprite();

    // Set rect from texture and frame
    void setProps(int x, int y, int w, int h, Uint8 speed);

    // Update every frame
    void Update();

    // Render
    void Render(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_RendererFlip flip);

private:
    SDL_Texture *m_texture;
    SDL_Rect m_src;

    Uint8 m_current_frame;
    Uint8 m_speed;
    Uint8 m_framecount;
};

#endif