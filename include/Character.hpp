#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <AnimatedSprite.hpp>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Vector.hpp>

class Character
{

public:
    Character(SDL_Renderer *render, std::string filename, Vect2D pos = {0, 0});
    ~Character();

    enum Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    void setDir(Direction dir);
    void update();
    void render(SDL_Renderer *render);

private:
    AnimatedSprite *sprite = nullptr;
    Vect2D position;
    Direction direction;
    SDL_Rect hitbox;
    int velocity;
};

#endif // CHARACTER_HPP
