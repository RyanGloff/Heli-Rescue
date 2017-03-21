#pragma once
#include <SDL.h>
#include "Environment.h"
#include "Object.h"
#include "Window.h"
#include <iostream>

class InputHandler
{
private:
	static SDL_Event ev;
	static bool* isRunning;
public:
	InputHandler();
	~InputHandler();
  //main input-handling function
	static void handle(bool& isRunning, Window& window);
	static void keyHandler(SDL_Event ev, Object& player, bool* isRunning);
	static void mouseHandler(SDL_Event ev);
};

