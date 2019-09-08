#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>
#include <string>

using namespace std;

#ifndef TEXTURE_H
#define TEXTURE_H
class Texture
{
public:
  //Initializes variables
  Texture();

  //Deallocates memory
  ~Texture();

  //Loads image at specified path
  bool loadFromFile(string path, SDL_Renderer *gRenderer = NULL);

  //Deallocates texture
  void free();

  //Set color modulation
  void setColor(Uint8 red, Uint8 green, Uint8 blue);

  //Set blending
  void setBlendMode(SDL_BlendMode blending);

  //Set alpha modulation
  void setAlpha(Uint8 alpha);

  //Renders texture at given point
  void render(int x, int y, SDL_Rect *clip = NULL, SDL_Renderer *gRenderer = NULL);

  //Gets image dimensions
  int getWidth();
  int getHeight();

private:
  //The actual hardware texture
  SDL_Texture *mTexture;

  //Image dimensions
  int mWidth;
  int mHeight;
};
#endif