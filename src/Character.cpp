#include <Character.hpp>

Character::Character(SDL_Renderer *render, std::string filename, Vect2D pos)
{
    sprite = new AnimatedSprite(render, filename);

    position = pos;
    velocity = 4;
    flip = SDL_FLIP_NONE;
    setDir(DOWN);
}

Character::~Character()
{
    delete sprite;
}

void Character::update()
{
    switch (direction)
    {
    case UP:
        position.y -= 1 * velocity;
        break;
    case DOWN:
        position.y += 1 * velocity;
        break;
    case RIGHT:
        position.x += 1 * velocity;
        break;
    case LEFT:
        position.x -= 1 * velocity;
        break;
    default:
        break;
    }

    sprite->Update();
}

void Character::render(SDL_Renderer *render)
{
    sprite->Render(render, position.x, position.y, 32, 48, flip);
}

void Character::setDir(Direction dir)
{
    if (direction != dir)
    {
        if (dir == NONE)
        {
            switch (direction)
            {
            case UP:
                sprite->setProps(16, 0, 16, 24, 0);
                break;
            case DOWN:
                sprite->setProps(16, 48, 16, 24, 0);
                break;
            case LEFT:
            case RIGHT:
                sprite->setProps(0, 24, 16, 24, 0);
                break;
            default:
                break;
            }
        }
        else
        {
            switch (dir)
            {
            case UP:
                sprite->setProps(0, 0, 16, 24, 4);
                break;
            case DOWN:
                sprite->setProps(0, 48, 16, 24, 4);
                break;
            case LEFT:
            case RIGHT:
                sprite->setProps(0, 24, 16, 24, 4);
                break;
            default:
                break;
            }

            flip = dir == RIGHT ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        }

        direction = dir;
    }
}