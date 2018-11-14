#pragma once
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent() { id = 2; };
	void update() { std::cout << "ControlComponent Updated" << std::endl; };
	int up(int y)
	{
		int ans = y - M_SPEED;
		return ans;
	};
	int down(int y)
	{
		int ans = y + M_SPEED;
		return ans;
	};
	int left(int x)
	{ 
		int ans = x - M_SPEED;
		return ans;
	};
	int right(int x)
	{
		int ans = x + M_SPEED;
		return ans;
	};

private:
	const int M_SPEED = 2;
};