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
			keyHandler(ev, player, &isRunning);
		}
		else if (ev.type == SDL_MOUSEBUTTONDOWN)
		{
			mouseHandler(ev);
		}
	}
}

void InputHandler::keyHandler(SDL_Event ev, Object& player, bool* isRunning)
{
	switch (ev.key.keysym.sym)
	{
	case SDLK_w:
		player.setYSpeed(-4);
		break;
	case SDLK_s:
		player.setYSpeed(3);
		break;
	case SDLK_ESCAPE:
		*isRunning = false;
		break;
	}
}

void InputHandler::mouseHandler(SDL_Event ev)
{
	std::cout << "We're getting mouse input" << std::endl;
}

