#pragma once
#include <iostream>

class Component
{
public:
	Component() {};
	~Component() { std::cout << "Component Destroyed" << std::endl; };
	virtual void update() { std::cout << "Component Updated" << std::endl; };
	int id = 0;
};