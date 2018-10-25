#pragma once
#include <vector>
#include "Component.h"

class Entity
{
	int id;
public:
	Entity() {};
	void addComponent(std::shared_ptr<Component> c) { components.push_back(c); };
	void removeComponent(std::shared_ptr<Component> c) { };
	std::vector<std::shared_ptr<Component>> getComponents() { return components; };

private:
	std::vector<std::shared_ptr<Component>> components;

};