#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include "InputHandler.h"
#include "Sounds.h"
#include "Window.h"
#include "Menu.h"
#include "Display.h"
#include "HighScoreController.h"

SDL_Event Menu::e;

void init(int argc, char* argv[]);
void tick();
void render();
void exit();

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;

Window* window = nullptr;
TTF_Font* Dfont = nullptr;
int size = 40;
Sounds bg("assets/bg.wav", "music");
Menu Main(1);
Display score;
Display lives;

HighScoreController hsc;


bool running = false;
bool start = true;

int main(int argc, char* argv[]) {
	init(argc, argv);

	const int TPS = 60;
	const int TIME_PER_TICK = 1000 / TPS;

	while (start || running) {

		while (start) {
			Menu::handleEvent(Menu::e, running, start);
			Main.render(Window::renderer);
			SDL_RenderPresent(Window::renderer);
			Display::lives = 3;
			}

		Uint32 startTick = SDL_GetTicks();
		Uint32 startRender = SDL_GetTicks();
		int frames = 0;

		while (running) {
			if (Display::lives == 0) {
				hsc.addScore(Display::score, "Unknown Player");
				std::vector<Score> highScores = hsc.getScores();
				std::cout << "Number of scores: " << highScores.size() << std::endl;
				for (Score s : highScores) {
					std::cout << s.toString() << std::endl;
				}
				start = true;
				running = false;
				Display::score = 0;
			}
			bg.play();
			score.scoreDsiplay(Window::renderer, 5, 5,Dfont);
			lives.livesDisplay(Window::renderer, 980, 5,Dfont);
			SDL_RenderPresent(Window::renderer);
			InputHandler::handle(running, *window);
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
		SDL_RenderClear(Window::renderer);
	}
	exit();
	return 0;
}

void init(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
	}
	if (SDL_Init(IMG_INIT_PNG < 0)) {
		std::cout << "SDL could not init pngs! SDL_Error: " << SDL_GetError() << std::endl;
	}
	int x;
	if (argv[1] != nullptr) {
		std::stringstream ss(argv[1]);
		ss >> x;
		srand(x);
	} else {
		//srand(time(NULL));
	}

	window = new Window("Heli-Rescue");

	if (TTF_Init() == -1) {
		std::cout << "could not init TTF" << std::endl;
	}
	Main.loadFont(60);
	Dfont = TTF_OpenFont("assets/vevey.ttf", size);
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
