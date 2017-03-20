#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Menu
{
	std::string text;
	TTF_Font* font = nullptr;
	SDL_Event e;
	bool quit;

public:
	Menu();
	Menu(char c, SDL_Renderer* renderer);
	~Menu();

	void render(SDL_Renderer* renderer);
	void mainMenu(SDL_Renderer* renderer);
	void exitMenu(SDL_Renderer* renderer);
	void textDisplay(std::string text, int x, int y, int size, int r, int g, int b, SDL_Renderer* renderer);
};

