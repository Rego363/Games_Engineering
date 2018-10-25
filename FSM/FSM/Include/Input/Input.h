#ifndef INPUT_H
#define INPUT_H

#include <FSM/Animation.h>
#include <SDL.h>
#include <iostream>
#include <FSM/State.h>
#include <Input/MacroCommand.h>

class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		IDLE,
		JUMP,
		CLIMB
	};

	void handleInput(SDL_Event & event);
	void setCurrent(Action);
	Action getCurrent();

private:
	Animation * fsm;
	Action m_current;
	State * buttonUP_;
	State * buttonDown_;
	State * buttonRight_;
	State * buttonU_;
	State * buttonR_;
	MacroCommand * macro;
};
#endif