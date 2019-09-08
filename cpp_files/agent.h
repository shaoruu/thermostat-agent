#include <SDL2/SDL.h>
#include <iostream>

#include "environment.h"
#include "texture.h"
#include "thermo.h"

#ifndef AGENT_H
#define AGENT_H
class Agent
{
private:
  bool isTuringAC = false;
  SDL_Rect gSpriteClips[23];
  Texture gSpriteSheetTexture;

  double x = 0;
  const double y = 448;

  static Agent *instance;

  Agent();

public:
  static Agent *getInstance();

  void loadMedia();
  void update();
  void sense();
  void decide();
  void act();
  void draw(int frame);
};
#endif