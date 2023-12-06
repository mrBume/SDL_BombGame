#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL.h>

class AnimatedSprite
{
public:

    struct Animation
    {
        std::vector<Uint8> frames;
        Uint8 speed;
    };

    // Constructor
    AnimatedSprite(SDL_Renderer *renderer, std::string filepath);

    // Destructor
    ~AnimatedSprite();

    // Set rect from texture and frame
    void setProps(std::string animation_index, Uint8 speed);

    // Update every frame
    void Update();

    // Render
    void Render(SDL_Renderer *renderer, int x, int y, int w, int h);

private:
    SDL_Texture *m_texture;
    
    // Uint8 m_current_frame;
    Uint8 m_speed;
    Uint8 m_framecount;

    std::string sprite_sheet;
    std::vector<SDL_Rect> sprites;
    std::unordered_map<std::string, Animation> animations;
    std::vector<Uint8>::iterator current_frame;
    std::string current_anim;
};

#endif
