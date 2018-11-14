#pragma once
#include "Component.h"

class PositionComponent : public Component
{
public:
	PositionComponent(int x, int y) : m_x(x), m_y(y) { id = 3; };
	int getX() { return m_x; };
	int getY() { return m_y; };
	void setX(int x) { 
		this->m_x = x;
		if (m_x > 1366)
		{
			m_x = -10;
		}
		else if (m_x < -10)
		{
			m_x = 1366;
		}
	};
	void setY(int y) {
		this->m_y = y;
		if (m_y > 768)
		{
			m_y = -10;
		}
		else if (m_y < -10)
		{
			m_y = 768;
		}
	};
	void update() { std::cout << "PositionComponent Updated" << std::endl; };

private:
	int m_x;
	int m_y;
};