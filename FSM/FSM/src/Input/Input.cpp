#include <Input\Input.h>

Input::Input()
{
	fsm = new Animation();
	m_current = IDLE;
}

Input::~Input()
{

}
void Input::setCurrent(Action a) {
	m_current = a;
}

Input::Action Input::getCurrent() {
	return m_current;
}



void Input::handleInput(SDL_Event & event)
{

	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			fsm->jumping();
			if (getCurrent() == IDLE)
				std::cout << "Jump called" << std::endl;
				setCurrent(JUMP);
			break;
		case SDLK_RIGHT:
			fsm->climbing();
			if (getCurrent() == IDLE)
				std::cout << "Climb called" << std::endl;
				setCurrent(CLIMB);
			break;
		case SDLK_DOWN:
			fsm->idle();
			std::cout << "Idle called" << std::endl;
			setCurrent(IDLE);
			break;

		}

	}

}