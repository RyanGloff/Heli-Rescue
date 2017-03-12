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
			keyHandler(ev, player);
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN)
		{
			mouseHandler(ev);
		}
	}
}

void InputHandler::keyHandler(SDL_Event ev, Object& player)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		player.setYSpeed(-10);
		break;
	case SDLK_s:
		player.setYSpeed(10);
		break;
	}
}

void InputHandler::mouseHandler(SDL_Event ev)
{
	std::cout << "We're getting mouse input" << std::endl;
}

