#pragma once
#include <iostream>
#include "Entity.h"
#include <vector>

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { 
		entities.push_back(e);
	};
	void update()
	{
		//std::cout << "Health System Update" << std::endl;
		// Loop through Entities with
		// HealthComponents and update
		// TBI

		std::vector<Entity>::iterator iter = entities.begin();
		for (; iter != entities.end(); iter++)
		{
			std::vector<std::shared_ptr<Component>> comps = (*iter).getComponents();
			//std::vector<Component>::iterator compIter = (*iter).getComponents().begin(); //comps.begin();
			//for (; compIter != (*iter).getComponents().end(); compIter++)
			for (std::shared_ptr<Component> compIter : (*iter).getComponents())
			{
				if ((*compIter).id == 1)
				{
					auto c = dynamic_cast<HealthComponent *>(&(*compIter));
					std::cout << c->getHealth() << std::endl;
				}
			}
		}
		//auto c = dynamic_cast<HealthComponent *>(component)

	}
};
