#include "ImageHandler.h"
#include "Window.h"

ImageHandler::ImageHandler() {
  std::string paths[] = {"bg.png", "bird.png", "building.png", "heli.png", "person.png"};
  SDL_Surface* surface = nullptr;
  for (int i = 0; i < paths.length; i++) {
    surface = IMG_Load("assets/" + paths[i]);
    if (surface == NULL) {
  		std::cerr << "IMG_Load: " << IMG_GetError();
  	}
    textures[i] = SDL_CreateTextureFromSurface(Window::renderer, surface);
  	if (textures[i] == NULL) {
  		std::cerr << "SDL_CreateTextureFromSurface: " << IMG_GetError() << "\n";
  	}
  	SDL_FreeSurface(surface);
  }



}

SDL_Texture* ImageHandler::getTexture(int num) {
  return textures[num];
}
