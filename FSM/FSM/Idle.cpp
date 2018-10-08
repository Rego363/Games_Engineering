#include "Idle.h"

void Idle::jumping(Animation* a)
{
	std::cout << "Jumping" << std::endl;
	a->setCurrent(new Jumping());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	a->idle();
	a->setCurrent(new Idle());
	delete this;
}

void Idle::climbing(Animation* a)
{
	std::cout << "Climbing" << std::endl;
	a->setCurrent(new Climbing());
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	a->idle();
	a->setCurrent(new Idle());
	delete this;
}