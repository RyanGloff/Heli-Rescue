#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Window.h"
#include "Sounds.h"

void init();
void tick();
void render();
void exit();

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

Window* window = nullptr;

bool running = true;

SDL_Event e;
 
 Sounds bg("bg.wav", "music");

int main(int argc, char* argv[]) {
	init();
	bg.play();
	const int TPS = 30;
	const int TIME_PER_TICK = 1000 / TPS;
	Uint32 startTick = SDL_GetTicks();
	Uint32 startRender = SDL_GetTicks();
	int frames = 0;
	while (running) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
				running = false;
			}
		}
		Uint32 currentTick = SDL_GetTicks();
		if (currentTick - startTick >= TIME_PER_TICK) {
			tick();
			startTick += TIME_PER_TICK;
		}
		render();
		frames++;
		Uint32 currentRender = SDL_GetTicks();
		if (currentRender - startRender > 1000) {
			startRender += 1000;
			std::cout << "FPS: " << frames << std::endl;
			frames = 0;
		}
	}
	exit();
	return 0;
}

void init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cout << "SDL_image could not initialize! SDL_image Error:" << IMG_GetError() << std::endl;
	}
	
	window = new Window("Heli-Rescue");


}

void tick() {
	window->tick();
}
void render() {
	window->render();
}

void exit() {
	delete window;
	window = nullptr;
}