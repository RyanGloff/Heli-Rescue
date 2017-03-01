#include "stdafx.h"
#include "SDL.h"
#include <iostream>
#include <stack>
#include <SDL_image.h>


//Constants
const int WINDOW_HEIGHT = 720;
const int WINDOW_WIDTH = 1080;
const int FRAMES_PER_SEC = 30;
const int FRAME_RATE = 1000/FRAMES_PER_SEC;
const char* WINDOW_TITLE = "SDL2 Menu";

//to use a fcn pointer as return type
struct gamePointerStruct {
	void(*functionPointer)();
};

//Globals
std::stack <gamePointerStruct> gameStack; 
SDL_Event e;
int timer = 0;

SDL_Surface* backgroundImage = NULL;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* pictureSurface = NULL;


//Functions

//Init and exit fcns
bool init();
void exit();

//Game states functions
void menuScreen();
void gameScreen();
void exitScreen();

//Handler fcns
void backgroundDraw();
void clear();

//Input fcns
void menuHandler();
void gameHandler();
void exitHandler();

/********MAIN FUNCTION********/
int main(int argc, char **argv) {
	
	init();

	//game loop
	while (!gameStack.empty()) {
		gameStack.top().functionPointer();
	}
	
	exit();
	return 0;
}

/********INITIALIZE FUNTION********/
bool init() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
		std::cout << "SDL could not initialize. SDL_ERROR: " << SDL_GetError() << std::endl;
		return false;
	}

	//Sets window, returns pointer, gets ticks since init
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	timer = SDL_GetTicks();
	if (window == NULL) {
		std::cout << "Window could not be created; SDL_ERROR: " << SDL_GetError() << std::endl;
		return false;
	}
	
	//loads background image to screen
	backgroundImage = SDL_GetWindowSurface(window);

	//Pointer to exit
	gamePointerStruct currentMenu;
	currentMenu.functionPointer = exitScreen;
	gameStack.push(currentMenu);

	//Pointer to menu
	currentMenu.functionPointer = menuScreen;
	gameStack.push(currentMenu);

	return true;
}

/********EXIT SDL FUNCTION********/
void exit() {
	//Quit everything, free up space
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(pictureSurface);
	SDL_FreeSurface(backgroundImage);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


/********GAME STATE FUNCTIONS********/

//Main menu fcn
void menuScreen() {
	//Updates frame to most recent one
	if ((SDL_GetTicks() - timer) >= FRAME_RATE) {
		menuHandler();

		//Clear current screen and display menu info
		clear();

		//displays buffer
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		//Displays a blue rectangle		
		SDL_RenderClear(renderer); 
		SDL_SetRenderDrawColor(renderer, 59, 0, 255, 255); 	
		SDL_Rect rect{ 0,0,1080,720 };
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer); 

		//Updates time frame is processed
		timer = SDL_GetTicks();
	}
}

//Displays game screen
void gameScreen() {
	//Updates frame to most recent one
	if ((SDL_GetTicks() - timer) >= FRAME_RATE) {
		//clears screen and displays current buffer
		clear();
		//backgroundDraw();

		//Displays a red rectangle
		SDL_RenderClear(renderer);
		
		SDL_Rect rect{ 0,0,1080,720 };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		
		gameHandler();

		//Updates time frame is processed
		timer = SDL_GetTicks();
	}
}

//Displays exit screen
void exitScreen() {
	if ((SDL_GetTicks() - timer) >= FRAME_RATE) {
		exitHandler();

		//clears screen and displays current buffer
		clear();
		//std::cout << "Quit Game? [Y/N]" << std::endl;
		
		//Displays a yellow rectangle
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 250, 0, 255);
		SDL_Rect rect{ 0,0,1080,720 };
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

		timer = SDL_GetTicks();
	}
}


/********HANDLER FUNTIONS********/

//draws the background
void backgroundDraw() {
	SDL_BlitSurface(pictureSurface, NULL, backgroundImage, NULL);
	SDL_UpdateWindowSurface(window);
}
	
//clears the screen
void clear() {
	SDL_FreeSurface(backgroundImage);
}

	
/********INPUT FUNCTIONS********/

//handles menu screen from player input
void menuHandler() {
	if (SDL_PollEvent(&e)) {
		//Handle manual close of game
		if (e.type == SDL_QUIT) {
			while (!gameStack.empty()) {
				gameStack.pop();
			}
			//ends game
			return;
		}

		//handles keyboard input
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) {
				gameStack.pop();
				//Stack done exits fcn
				return;
			}
			//Quits game
			else if (e.key.keysym.sym == SDLK_q) {
				std::cout << "Want to quit?" << std::endl;
				gameStack.pop();
				return;
			}
			//Starts game
			else if(e.key.keysym.sym == SDLK_g) {
				std::cout << "Play Game" << std::endl << "Playing Game";
				gamePointerStruct temp;
				temp.functionPointer = gameScreen;
				gameStack.push(temp);
				return;
			}
		}
	}
}

//Handles game input
void gameHandler() {
	if (SDL_PollEvent(&e)) {
		//Handle user manually closing game
		if (e.type == SDL_QUIT) {
			//While stack not empty
			while (!gameStack.empty()) {
				gameStack.pop();
			}

			//game quits
			return;
		}
		//Handles keyboard input
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) {
				std::cout << std::endl << "Escape the game fcn";
				gameStack.pop();
				//exits fcn
				return;
			}
		}
		//You "die" in game
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_d) {
				std::cout << std::endl << "Die in game" << std::endl;
				gameStack.pop();
				//exits fcn
				return;
			}
		}
	}
}

//Handles exit screens
void exitHandler() {
	if (SDL_PollEvent(&e)) {
		//Handles user manual close
		if (e.type == SDL_QUIT) {
			//while stack not empty
			while (!gameStack.empty()) {
				gameStack.pop();
			}
			//quits game
			return;
		}
		//Asking to quit game
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_y) {
				std::cout << "Yes" << std::endl;
				gameStack.pop();
				//quits game
				return;
			}
			//Stay on screen
			if (e.key.keysym.sym == SDLK_n) {
				std::cout << std::endl << "No" << std::endl;
				gamePointerStruct temp;
				temp.functionPointer = menuScreen;
				gameStack.push(temp);
				//exit fcn
				return;
			}
		}
	}
}

