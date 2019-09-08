#include "agent.h"

using namespace std;

Agent::Agent() {}

Agent *Agent::instance = 0;

Agent *Agent::getInstance()
{
  if (instance == 0)
    instance = new Agent();
  return instance;
}

void Agent::loadMedia()
{
  if (!gSpriteSheetTexture.loadFromFile("./characters.png", Thermo::getInstance()->getRenderer()))
    cerr << "Failed to load walking animation texture!" << endl;

  for (int i = 0; i < 23; i++)
  {
    gSpriteClips[i].x = i * 32;
    gSpriteClips[i].y = 32;
    gSpriteClips[i].w = 32;
    gSpriteClips[i].h = 32;
  }
}

void Agent::update()
{
  sense();
  decide();
  act();
}

void Agent::sense()
{
}

void Agent::decide()
{
}

void Agent::act()
{
}

void Agent::draw(int frame)
{
  SDL_Rect *currentClip = &gSpriteClips[frame / 4];
  gSpriteSheetTexture.render((480 - currentClip->w) / 2, 50, currentClip);
  cout << frame / 4 << endl;
}