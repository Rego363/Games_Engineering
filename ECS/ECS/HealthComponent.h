#pragma once

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() : health(100) {};
	// Data Only
	int getHealth() { return health; };
	void setHealth(int health) { this->health = health; };
	void update() { std::cout << "HealthComponent Updated" << std::endl; };

private:
	int health;
};