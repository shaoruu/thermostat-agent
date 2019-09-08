#pragma once

#include <SDL2/SDL.h>
#include <cassert>
#include "environment.h"
#include "agent.h"

class Thermo
{
private:
  SDL_Window *gWindow;
  SDL_Event event;
  SDL_Renderer *gRenderer;

  static Thermo *instance;

  Thermo();

public:
  static Thermo *getInstance();

  void loadMedia();
  void gameLoop();
  void update();
  void draw(int frame);

  SDL_Renderer *getRenderer();
};