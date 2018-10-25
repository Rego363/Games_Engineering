#pragma once
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent() : x(5), y(5) {};
	int getX() { return x; };
	int getY() { return y; };
	void setX(int x) { this->x = x; };
	void setY(int y) { this->y = y; };
	void update() { std::cout << "PositionComponent Updated" << std::endl; };

private:
	int x;
	int y;
};