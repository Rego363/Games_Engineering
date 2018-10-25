
#include <FSM\Climbing.h>

#include <string>

void Climbing::idle(Animation* a)
{
	std::cout << "Climbing -> Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Climbing::jumping(Animation* a)
{
	std::cout << "Climbing -> Jump" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}

void Climbing::undo(Animation* a)
{
	std::cout << "Undo Climbing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
};

void Climbing::redo(Animation* a)
{
	std::cout << "Redo Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
};