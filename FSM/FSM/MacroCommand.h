#pragma once
#include "Command.h"
#include <iostream>
#include <list>

class MacroCommand : public Command
{
public:
	MacroCommand();
	virtual ~MacroCommand();
	virtual void add(Command*);
	virtual void remove(Command*);
	virtual void execute();
	virtual void undo();
private:
	std::list<Command *> commands;
};