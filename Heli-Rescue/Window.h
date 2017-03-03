#pragma once
#include <SDL.h>

#include "Environment.h"

class Window {
private:
	static const int WIDTH = 1080;
	static const int HEIGHT = 720;
	char* title;

	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Renderer* renderer = nullptr;

	Environment* env;
public:
	Window(char* title);
	~Window();

	void render();
	void tick();
};

