#include <vector>
#include <iostream>

class Production{
public:
	int someMethod(int a);
	bool inRange(int a);
	bool inRange(std::vector<int> v);
	bool noRepeats(std::vector<int> v);
	bool rightSize(std::vector<int> v);
};
