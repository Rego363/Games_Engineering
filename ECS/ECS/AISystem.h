#pragma once

#include <iostream>
#include "Entity.h"
#include <vector>
#include "PositionComponent.h"
#include <cstdlib>

class AISystem
{
	std::vector<Entity> entities;
	std::vector<int> ranNum;
	PositionComponent * p;
	const int M_SPEED = 2;

public:
	void addEntity(Entity e) { 
		entities.push_back(e);
		ranNum.push_back(rand() % 4);
	};
	void update()
	{
		//std::cout << "AI System Update" << std::endl;
		// Loop through Entities with
		// AIComponents and update

		std::vector<Entity>::iterator iter = entities.begin();
		std::vector<int>::iterator iterRan = ranNum.begin();
		for (; iter != entities.end(); iter++, iterRan++)
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
								
					switch (*iterRan)
					{
					case 0:
						p->setY(M_SPEED - p->getY());
						break;
					case 1:
						p->setY(M_SPEED + p->getY());
						break;
					case 2:
						p->setX(M_SPEED - p->getX());
						break;
					case 3:
						p->setX(M_SPEED + p->getX());
						break;
					}
					
				}
			}
		}

		// TBI
	}
};