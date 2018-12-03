#include <vector>
#include <iostream>
#include <sstream> 
#include <algorithm>
#include <ctime>




class Production{
public:
	int someMethod(int a);
	bool inRange(int a);
	bool inRange(std::vector<int> v);
	bool noRepeats(std::vector<int> v);
	bool rightSize(std::vector<int> v);
	std::vector<int> takeInput();
	std::vector<int> generateWinners();
	bool checkTicket(std::vector<int> t, std::vector<int> w);
};
