#include "Display.h"
#include <SDL_ttf.h>
#include <sstream>
#include <string.h>


Display::Display() {

}

Display::~Display() {


}

void Display::scoreDsiplay(SDL_Renderer *renderer,int x,int y ) {
	
	SDL_Rect Rect = { x,y,w,h };

	std::stringstream strm;
	strm << "Score:  " << score;

	TTF_Font* font = TTF_OpenFont("assets/vevey.ttf", size);
	SDL_Color color = { r, g, b };

	SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, strm.str().c_str(), color);
	SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

	SDL_QueryTexture(scoreTexture, NULL, NULL, &w, &h);

	
	SDL_RenderCopy(renderer, scoreTexture, nullptr, &Rect);
	//SDL_RenderPresent(renderer);
	
	TTF_CloseFont(font);

}

void Display::livesDisplay(SDL_Renderer *renderer,int x,int y) {
	
	SDL_Rect livesRect = { x,y,w,h };

	std::stringstream strm;
	strm << "Lives:  " << lives;

	TTF_Font* font = TTF_OpenFont("assets/vevey.ttf", size);
	SDL_Color color = { r, g, b };

	SDL_Surface* livesSurface = TTF_RenderText_Solid(font, strm.str().c_str(), color);
	SDL_Texture* livesTexture = SDL_CreateTextureFromSurface(renderer, livesSurface);

	SDL_QueryTexture(livesTexture, NULL, NULL, &w, &h);


	SDL_RenderCopy(renderer, livesTexture, nullptr, &livesRect);
	//SDL_RenderPresent(renderer);

	TTF_CloseFont(font);
}

