#include <string>
#include <FSM\Idle.h>
#include <FSM\Jumping.h>
#include <FSM\Climbing.h>


void Idle::handleInput() {};
void Idle::update() {};

void Idle::jumping(Animation* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(Animation* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}