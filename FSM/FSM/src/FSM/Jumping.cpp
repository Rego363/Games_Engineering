#include <string>
#include <FSM\Jumping.h>
#include <FSM\Climbing.h>
#include <FSM\Idle.h>


void Jumping::idle(Animation* a)
{
	std::cout << "Jumping -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Jumping::climbing(Animation* a)
{
	std::cout << "Jumping -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Jumping::undo(Animation* a)
{ 
	std::cout << "Undo Jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
};

void Jumping::redo(Animation* a)
{
	std::cout << "Redo Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
};