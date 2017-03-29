#include <iostream>
#include <SDL.h>
#include "InputHandler.h"
#include "Sounds.h"
#include "Window.h"
#include "Menu.h"

SDL_Event Menu::e;

void init();
void tick();
void render();
void exit();

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

Window* window = nullptr;
Sounds bg("assets/bg.wav", "music");
Menu Main(1);


bool running = false;
bool start = true;


int main(int argc, char* argv[]) {
	init();
	const int TPS = 60;
	const int TIME_PER_TICK = 1000 / TPS;
	while (start) {
		Menu::handleEvent(Menu::e, running, start);
		Main.render(Window::renderer);
	}
	
	Uint32 startTick = SDL_GetTicks();
	Uint32 startRender = SDL_GetTicks();
	int frames = 0;
	
	
	
	while (running) {	
		InputHandler::handle(running, *window);
		bg.play();
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
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	window = new Window("Heli-Rescue");

	if (TTF_Init() == -1) {
		std::cout << "could not init TTF" << std::endl;
	}
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