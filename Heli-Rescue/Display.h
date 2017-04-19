#pragma once
#include <SDL.h>
#include <SDL_ttf.h>


class Display {

private:
	int r = 0, g = 0, b = 0;
	int x, y;
	int w = 10;
	int h = 10;
	int size = 40;


public:
	Display();
	~Display();
	void scoreDsiplay(SDL_Renderer *renderer,int x,int y,TTF_Font* font);
	void livesDisplay(SDL_Renderer *renderer,int x, int y,TTF_Font* font);
	static int score;
	static int lives;

};
