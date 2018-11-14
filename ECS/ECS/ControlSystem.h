#pragma once

#include <iostream>
#include "Entity.h"
#include <vector>
#include <SDL.h>

class ControlSystem
{
	std::vector<Entity> entities;
	PositionComponent * p;
	

public:
	void addEntity(Entity e) { 
		entities.push_back(e);
	};

	void update(SDL_Event & event)
	{
		//std::cout << "Control System Update" << std::endl;
		// Loop through Entities with
		// ControlComponents and update

		std::vector<Entity>::iterator iter = entities.begin();

		for (; iter != entities.end(); iter++)
		{
			std::vector<std::shared_ptr<Component>> comps = (*iter).getComponents();
			//std::vector<Component>::iterator compIter = (*iter).getComponents().begin(); //comps.begin();
			//for (; compIter != (*iter).getComponents().end(); compIter++)
			for (std::shared_ptr<Component> compIter : (*iter).getComponents())
			{
				// Get position component
				if ((*compIter).id == 3)
				{
					p = dynamic_cast<PositionComponent *>(&(*compIter));
				}

				if ((*compIter).id == 2 && p != NULL)
				{
					auto c = dynamic_cast<ControlComponent *>(&(*compIter));

					switch (event.type)
					{
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							p->setY(c->up(p->getY()));
							break;
						case SDLK_DOWN:
							p->setY(c->down(p->getY()));
							break;
						case SDLK_RIGHT:
							p->setX(c->right(p->getX()));
							break; 
						case SDLK_LEFT:
							p->setX(c->left(p->getX()));
							break;

						}

					}
				}
			}
		}

		// TBI
	}
};