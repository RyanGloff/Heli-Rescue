#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>


class Menu
{
	std::string text;
	TTF_Font* font = nullptr;
	//static SDL_Event e;
	bool quit;
	SDL_Surface* textSurface;
	SDL_Texture* textTexture;

	static const int MAIN_MENU = 0;
	static const int EXIT_MENU = 1;

	int state = 0;

public:
	static SDL_Event e;

	Menu();
	Menu(int initState);
	~Menu();

	static void handleEvent(SDL_Event e,bool& isRunning, bool& isStart,bool& isBegin);

	void render(SDL_Renderer* renderer);
	void mainMenuRender(SDL_Renderer* renderer);
	void exitMenuRender(SDL_Renderer* renderer);
	
	void setState(int state);
	int getState();
	
	void textDisplay(std::string text, int x, int y, int size, int r, int g, int b, SDL_Renderer* renderer);
};

