#pragma once
#include <SDL.h>
#include "Environment.h"

class Window {
private:
	static const int WIDTH = 1080;
	static const int HEIGHT = 720;
	char* title;
	SDL_Window* window = nullptr;
	Environment* env;
public:
	Window(char* title);
	~Window();
	void render();
	void tick();
	Environment& getEnv();
	static SDL_Renderer *renderer;
	static SDL_Surface *surface;
};

