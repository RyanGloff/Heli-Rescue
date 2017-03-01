#include "InputHandler.h"

InputHandler::InputHandler()
{ 
}
InputHandler::~InputHandler()
{
}

void InputHandler::handle(bool& isRunning, Window& window)
{	
	SDL_Event ev;

	Environment& target = window.getEnv();

	Object& player = target.getPlayer();

	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.type == SDL_QUIT)
		{
			isRunning = false;
		}
		else if (ev.type == SDL_KEYDOWN)
		{
			switch (ev.key.keysym.sym)
			{
			case SDLK_w:
				player.setYSpeed(-10);
				break;
			}
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << "We're getting mouse input" << std::endl;
		}
	}
}
