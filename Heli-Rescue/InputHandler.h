#pragma once
#include <SDL.h>
#include "Environment.h"
#include "Object.h"
#include "Window.h"
#include <iostream>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
  //main input-handling function
	static void handle(bool& isRunning, Window& window);
};

