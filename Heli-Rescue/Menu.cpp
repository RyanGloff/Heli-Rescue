#include "Menu.h"
#include <iostream>

Menu::Menu() {}
Menu::~Menu() {}

Menu::Menu(int initState) {
	state = initState;
}

void Menu::render(SDL_Renderer* renderer) {
	if (state == MAIN_MENU) {
		mainMenuRender(renderer);
	} else if (state == EXIT_MENU) {
		exitMenuRender(renderer);
	}
}

void Menu::mainMenuRender(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	std::cout << "In mainMenu" << std::endl;

	textDisplay("Welcome to Heli-Rescue!", 40, 40, 100, 0, 85, 255, renderer);
	textDisplay("Start Game [G]", 40, 160, 72, 255, 230, 0, renderer);
	textDisplay("Quit Game [Q]", 40, 260, 72, 50, 255, 0, renderer);

	std::cout << "Everything displayed on screen" << std::endl;
}

void Menu::exitMenuRender(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	textDisplay("Are you sure you want to quit? [Y/N]", 40, 360, 72, 255, 25, 0, renderer);
	std::cout << "sure you want to quit?";
}

void Menu::handleEvent(SDL_Event* e) {
	if (state == MAIN_MENU) {
		if (e->key.keysym.sym == SDLK_g) {
			std::cout << "Start the game" << std::endl;
		}
	}
	else if (state == EXIT_MENU) {
		// Set key functions for exit menu here
	}
	
}

void Menu::setState(int state) {
	this->state = state;
}
int Menu::getState() {
	return state;
}

void Menu::textDisplay(std::string text, int x, int y, int size, int r, int g, int b, SDL_Renderer* renderer) {
	TTF_Font* font = TTF_OpenFont("vevey.ttf", size);
	SDL_Color color = { r, g, b };

	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	int w = 0;
	int h = 0;
	SDL_QueryTexture(textTexture, NULL, NULL, &w, &h);
	SDL_Rect textRect = { x, y, w, h };

	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	SDL_RenderPresent(renderer);

	SDL_DestroyTexture(textTexture);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}