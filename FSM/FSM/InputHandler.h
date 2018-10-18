#pragma once
#include "Command.h"
#include "MacroCommand.h"
#include "Animation.h"
#include <SDL.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	void handleInput(SDL_Event & event);

private:
	Command * buttonX_;
	Command * buttonY_;
	Command * buttonC_;
	Command * buttonA_;
	Command * buttonB_;
	MacroCommand * macro;

	Animation * fsm;
};