#include "Window.h"

#include <iostream>

Window::Window(char* title) : title(title) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	env = *(new Environment(WIDTH, HEIGHT, 1));
}

Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Window::render() {
	SDL_Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 100;
	rect.h = 100;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	env.render(renderer);

	SDL_RenderPresent(renderer);
}
void Window::tick() {
	env.tick();
}

Environment& Window::getEnv()
{
	return this->env;
}	
