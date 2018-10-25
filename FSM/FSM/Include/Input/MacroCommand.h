#pragma once
#include <FSM/State.h>
#include <iostream>
#include <list>

class MacroCommand : public State
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(State*);
	virtual void remove(State*);
	virtual void execute();
	virtual void undo(Animation* anime);
	virtual void redo(Animation* anime);
private:
	std::list<State *> commands;
	std::list<State *> undoneCommands;
};