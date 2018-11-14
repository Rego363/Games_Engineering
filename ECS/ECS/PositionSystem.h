#pragma once
#include <iostream>
#include "Entity.h"
#include <vector>
#include <string>
#include <iterator>

class PositionSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); };
	void update()
	{
		//std::cout << "Position System Update" << std::endl;
		// Loop through Entities with
		// PositionComponents and update
		
		std::vector<Entity>::iterator iter = entities.begin();
		for (; iter != entities.end(); iter++)
		{
			std::vector<std::shared_ptr<Component>> comps = (*iter).getComponents();
			//std::vector<Component>::iterator compIter = (*iter).getComponents().begin(); //comps.begin();
			//for (; compIter != (*iter).getComponents().end(); compIter++)
			for(std::shared_ptr<Component> compIter : (*iter).getComponents())
			{
				if ((*compIter).id == 3)
				{
					auto c = dynamic_cast<PositionComponent *>(&(*compIter));
				}
			}
		}

		// TBI
	}
};