#include <iostream>
#include <SDL2/SDL.h>
#include "SDLApp.hpp"
#include "AnimatedSprite.hpp"
#include "Character.hpp"

using namespace std;

const int WIDTH = 500;
const int HEIGHT = 320;

const string char_sprite_data = "assets/sprites.dat";

SDLApp *app = nullptr;
Character *ramiro = nullptr;

void eventHandler()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      app->setRunningFlag(false);
      break;

    default:
      break;
    }
  }

  const Uint8 *keyboard_state = SDL_GetKeyboardState(nullptr);

  if (keyboard_state[SDL_SCANCODE_W])
    ramiro->setDir(Character::UP);
  else if (keyboard_state[SDL_SCANCODE_A])
    ramiro->setDir(Character::LEFT);
  else if (keyboard_state[SDL_SCANCODE_S])
    ramiro->setDir(Character::DOWN);
  else if (keyboard_state[SDL_SCANCODE_D])
    ramiro->setDir(Character::RIGHT);
  else
    ramiro->setDir(Character::NONE);

  ramiro->update();
}

void renderHandler()
{
  SDL_Renderer *render = app->getRenderer();

  SDL_SetRenderDrawColor(render, 127, 127, 127, 255);
  SDL_RenderClear(render);

  ramiro->render(render);

  SDL_RenderPresent(render);
}

int main(int argc, char *argv[])
{
  bool isRunning = true;

  app = new SDLApp("Bombman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT);
  ramiro = new Character(app->getRenderer(), char_sprite_data, {100, 100});

  app->setEventCallback(eventHandler);
  app->setRenderCallback(renderHandler);

  app->runLoop();

  delete app;
  delete ramiro;

  return EXIT_SUCCESS;
}