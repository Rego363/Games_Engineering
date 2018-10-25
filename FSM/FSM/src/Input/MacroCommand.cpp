#include <Input/MacroCommand.h>

MacroCommand::MacroCommand()
{

}

MacroCommand::~MacroCommand()
{
	std::cout << "deconstructing" << std::endl;
}

void MacroCommand::add(State* state)
{
	commands.push_back(state);
	undoneCommands.clear();
}

void MacroCommand::remove(State* state)
{
	commands.remove(state);
}


void MacroCommand::execute()
{
	std::cout << "executed" << std::endl;
}

void MacroCommand::undo(Animation* anime)
{

	if (commands.size() > 0)
	{
		(*commands.rbegin())->undo(anime);
		undoneCommands.push_back(*commands.rbegin());
		commands.pop_back();
	}

}

void MacroCommand::redo(Animation* anime)
{
	if (undoneCommands.size() > 0)
	{
		(*undoneCommands.rbegin())->redo(anime);
		commands.push_back(*undoneCommands.rbegin());
		undoneCommands.pop_back();
	}
}