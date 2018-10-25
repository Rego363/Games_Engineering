#pragma once
#include <iostream>
#include "Entity.h"
#include <vector>

class HealthSystem
{
	std::vector<Entity> entities;

public:
	void addEntity(Entity e) { entities.push_back(e); };
	void update()
	{
		//std::cout << "Health System Update" << std::endl;
		// Loop through Entities with
		// HealthComponents and update
		// TBI
	}
};
