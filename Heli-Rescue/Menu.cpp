#include "stdafx.h"
#include "Menu.h"
#include <iostream>

Menu::Menu() {}
Menu::~Menu() {}

Menu::Menu(char c, SDL_Renderer* renderer) {

	SDL_RenderClear(renderer);

	if (c == 'M') {
		std::cout << "In M construtor" << std::endl;
		mainMenu(renderer);
	}
	else if (c == 'E') {
		std::cout << "In E construtor" << std::endl;
		exitMenu(renderer);
	}
}

void Menu::render(SDL_Renderer* renderer){
  //does nothing currently
}

void Menu::mainMenu(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	std::cout << "In mainMenu" << std::endl;
	
	textDisplay("Welcome to Heli-Rescue!", 40, 40, 100, 0, 85, 255, renderer);
	textDisplay("Start Game [G]", 40, 160, 72, 255, 230, 0, renderer);
	textDisplay("Quit Game [Q]", 40, 260, 72, 50, 255, 0, renderer);
	
	std::cout << "Everything displayed on screen" << std::endl;

	
	while (!quit || SDL_PollEvent(&e) != 0)
	{
		SDL_WaitEvent(&e);

		switch (e.type)
		{
			case SDL_QUIT:
				quit = true;
				SDL_RenderClear(renderer);
				break;
			case SDLK_g:
				render(renderer);
				textDisplay("Playing game", 40, 40, 72, 255, 255, 35, renderer);
				break;
			case SDLK_q:
				exitMenu(renderer);
				break;
		}
	}
}

void Menu::exitMenu(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	std::cout << "In exitMenu" << std::endl;
	textDisplay("Are you sure you want to quit? [Y/N]", 40, 360, 72, 255, 25, 0, renderer);
	std::cout << "sure you want to quit?";

	while (!quit || SDL_PollEvent(&e) != 0)
	{
		SDL_WaitEvent(&e);

		switch (e.type)
		{
			case SDL_QUIT:
				quit = true;
				SDL_RenderClear(renderer);
				break;
			case SDLK_n:
				mainMenu(renderer);
				break;
			case SDLK_y:
				SDL_Quit();
				break;
		}
	}
}

void Menu::textDisplay(std::string text, int x, int y, int size, int r, int g, int b, SDL_Renderer* renderer) {
	std::cout << "In text display" << std::endl;
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
