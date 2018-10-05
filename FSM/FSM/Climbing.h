#pragma once
#include "Idle.h"
#include "State.h"
#include <iostream>

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
};