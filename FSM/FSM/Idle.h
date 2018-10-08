#pragma once
#include "State.h"
#include "Jumping.h"
#include "Climbing.h"
#include <iostream>
#include <chrono>
#include <thread>

class Animation;

class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation* a);
	void climbing(Animation* a);

};