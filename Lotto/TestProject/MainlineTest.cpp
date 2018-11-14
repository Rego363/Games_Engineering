#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Production p;

	int a = 0;
	std::vector<int> v;
	v.push_back(45);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	//cin >> a;
	//cout << a << endl;

	//cout << p.someMethod(a) << endl;
	for (int i = 0; i < v.size(); i++)
	{
		//assert(p.inRange(v[i]) == true);
	}

	assert(p.inRange(v) == true);
	assert(p.noRepeats(v) == true);
	assert(p.rightSize(v) == true);	


	std::vector<int> vr;
	vr.push_back(48);
	vr.push_back(0);
	vr.push_back(3);
	vr.push_back(3);
	vr.push_back(5);

	for (int i = 0; i < v.size(); i++)
	{
		//assert(p.inRange(v[i]) == true);
	}

	assert(p.inRange(v) == true);
	assert(p.noRepeats(v) == true);
	assert(p.rightSize(v) == true);


	system("PAUSE");
}

