#pragma once

#include <SDL_image.h>
#include <SDL2.h>

class ImageHandler {
private:
  std::vector<SDL_Texture> textures;
public:
  static const int BG;
  static const int BIRD;
  static const int BUILDING;
  static const int HELI;
  static const int PLAYER;


  ImageHandler();

  SDL_Texture* getTexture(int num);

};
ImageHandler::BG = 0;
ImageHandler::BIRD = 1;
ImageHandler::BUILDING = 2;
ImageHandler::HELI = 3;
ImageHandler::PLAYER = 4;
