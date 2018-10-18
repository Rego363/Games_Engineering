#include "InputHandler.h"

InputHandler::InputHandler()
{
	macro = new MacroCommand();

	fsm = new Animation();

}

InputHandler::~InputHandler()
{

}

void InputHandler::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_i:
			fsm->idle();
			break;
		case SDLK_u:
			fsm->jumping();
			break;
		case SDLK_o:
			fsm->climbing();
			break;
		}

	}

}