#include <Character.hpp>

Character::Character(SDL_Renderer *render, std::string filename, Vect2D pos)
{
    sprite = new AnimatedSprite(render, filename);

    position = pos;
    velocity = 4;
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
    sprite->Render(render, position.x, position.y, 32, 48);
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
                sprite->setProps("IU", 0);
                break;
            case DOWN:
                sprite->setProps("ID", 0);
                break;
            case LEFT:
                sprite->setProps("IL", 0);
                break;
            case RIGHT:
                sprite->setProps("IR", 0);
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
                sprite->setProps("UP", 4);
                break;
            case DOWN:
                sprite->setProps("DOWN", 4);
                break;
            case LEFT:
                sprite->setProps("LEFT", 4);
                break;
            case RIGHT:
                sprite->setProps("RIGHT", 4);
                break;
            default:
                break;
            }

        }

        direction = dir;
    }
}
