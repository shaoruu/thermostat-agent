#include "thermo.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Thermo *Thermo::instance = 0;

Thermo *Thermo::getInstance()
{
  if (instance == 0)
    instance = new Thermo();
  return instance;
}

Thermo::Thermo()
{
  SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &gWindow, &gRenderer);

  SDL_RenderSetLogicalSize(gRenderer, 400, 400);
}

void Thermo::loadMedia()
{
  Agent::getInstance()->loadMedia();
}

void Thermo::gameLoop()
{
  bool quit = false;
  int frame = 0;

  while (!quit)
  {
    while (SDL_PollEvent(&event) > 0)
    {
      switch (event.type)
      {
      case SDL_QUIT:
        quit = true;
        break;
      }

      // Environment::getInstance()->incrTemp(123);
    }

    update();
    draw(frame);

    frame++;

    // Reset frame to prevent exceeding
    if (frame / 4 >= 23)
      frame = 0;
  }
}

void Thermo::update()
{
  // UPDATES
  Environment::getInstance()->update();
  Agent::getInstance()->update();
}

void Thermo::draw(int frame)
{
  SDL_Renderer *temp = getInstance()->getRenderer();

  SDL_SetRenderDrawColor(temp, 93, 151, 141, 1);
  SDL_RenderClear(temp);

  Agent::getInstance()->draw(frame);

  SDL_RenderPresent(temp);
}

SDL_Renderer *Thermo::getRenderer()
{
  return gRenderer;
}