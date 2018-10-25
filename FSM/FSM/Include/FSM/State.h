#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <FSM\Animation.h>
#include <Debug\Debug.h>

class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
	}
	virtual void redo(Animation* a)
	{
		DEBUG_MSG("Redo");
	}
	virtual void undo(Animation* a)
	{
		DEBUG_MSG("Undo");
	}
};

#endif // ! ANIMATION_H

