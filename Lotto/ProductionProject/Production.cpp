#include "Production.h"

int Production::someMethod(int a)
{
	return a - a;
}

bool Production::inRange(int a)
{
	// Over max
	if (a > 46)
	{
		std::cout << a << " is over 46." << std::endl;
		return false;
	}
	else if (a < 1) // under min
	{
		std::cout << a << " is under 1." << std::endl;
		return false;
	}

	// Number in range
	return true;
}

bool Production::inRange(std::vector<int> v)
{
	// Loop through elements
	for (int i = 0; i < v.size(); i++)
	{
		// Over max
		if (v[i] > 46)
		{
			std::cout << "Element " << i + 1 << " on your ticket is over 46." << std::endl;
			return false;
		}
		else if (v[i] < 1) // Under min
		{
			std::cout << "Element " << i + 1 << " on your ticket is under 1." << std::endl;
			return false;
		}
	}
	
	// All numbers in range
	return true;
}

bool Production::noRepeats(std::vector<int> v)
{
	// Outer loop
	for (int i = 0; i < v.size(); i++)
	{
		// Inner loop
		for (int j = 0; j < v.size(); j++)
		{
			// Check to make sure elements arent being compared to themselves
			if (i != j)
			{
				// Checking if two elements have the same value
				if (v[i] == v[j])
				{
					// Numbers are being repeated
					std::cout << "Elements " << i + 1 << " and " << j + 1 << " have the same value." << std::endl;
					return false;
				}
			}
		}
	}

	// Numbers are not being repeated
	return true;
}

bool Production::rightSize(std::vector<int> v)
{
	// Under required size
	if (v.size() < 6)
	{
		std::cout << "You need " << 6 - v.size() << " more number(s)." << std::endl;
		return false;
	}
	else if (v.size() > 6) // Under required size
	{
		std::cout << "You have " << 6 - v.size() << " number(s) too many." << std::endl;
		return false;
	}
	return true;
};