#ifndef CLIMBING_H
#define CLIMBING_H

#include <FSM\State.h>
#include <FSM\Jumping.h>
#include <FSM\Idle.h>

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
};

#endif // !IDLE_H