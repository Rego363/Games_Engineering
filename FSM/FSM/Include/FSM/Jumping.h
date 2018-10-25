#ifndef JUMPING_H
#define JUMPING_H

#include <FSM\State.h>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
	void climbing(Animation* a);
	virtual void undo(Animation* a);
	virtual void redo(Animation* a);
};

#endif // !IDLE_H