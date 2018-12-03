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

bool Production::noRepeats(std::vector<int> v){
	for (int i = 0; i < v.size(); i++){ // Outer loop	
		for (int j = 0; j < v.size(); j++){ // Inner loop
			if (i != j) { // Check to make sure elements arent being compared to themselves
				if (v[i] == v[j]) {	// Checking if two elements have the same value
					std::cout << "Elements " << i + 1 << " and " << j + 1 << " have the same value." << std::endl; // 15
					return false;	// Numbers are being repeated
				}
			}	
		}
	}
	return true;	// Numbers aren't being repeated
}

bool Production::rightSize(std::vector<int> v)
{
	// Under required size
	if (v.size() < 6)
	{
		std::cout << "You need " << 6 - v.size() << " more number(s)." << std::endl;
		return false;
	}
	else if (v.size() > 6) // Over required size
	{
		std::cout << "You have " << v.size() - 6 << " number(s) too many." << std::endl;
		return false;
	}
	return true;
};

std::vector<int> Production::takeInput(){
	std::vector<int> ans;
	bool cont = false;
	while (!cont){	//3
		std::string input;
		std::cout << "Enter the numbers you would like on your ticket." << std::endl;
		std::cout << "Seperate your numbers with a space." << std::endl;	// 6
		std::getline(std::cin, input);
		while (input.length() > 0){
			const char * check = " ";	//9
			while (input[0] == *check){
				input.erase(0, 1);
			}	//12
			bool numOnly = true;	
			std::string delimiter = " ";
			std::string token = input.substr(0, input.find(delimiter));	//15
			for (int i = 0; i < token.length(); i++){
				int temp = (int)token[i];
				if (temp > 58 && temp < 47){	//18
					numOnly = false;
				}
			}	//21
			if (numOnly){
				ans.push_back(std::stoi(token));
			} //24
			numOnly = true;
			input.erase(0, token.length() + 1);
		}	//27
		if (!rightSize(ans) || !noRepeats(ans) || !inRange(ans)){
			std::cout << "Enter the picks for your ticket again." << std::endl;
			ans.clear(); //30
			cont = false;
		}
		else{	//33
			cont = true;
		}
	}	// 36	return ans;
};

std::vector<int> Production::generateWinners()
{
	std::vector<int> ans;
	int temp;
	srand(time(NULL));
	for (int i = 0; i < 6; i++)
	{
		temp = rand() % 46 + 1;
		for (int j = 0; j < ans.size(); j++)
		{
			while (temp == ans[j])
			{
				temp = rand() % 46 + 1;
			}
		}

		ans.push_back(temp);
	}
	std::sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << i + 1 << ": " << ans[i] << std::endl;
	}
	return ans;
};

bool Production::checkTicket(std::vector<int> t, std::vector<int> w)
{
	std::vector<bool> correct;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < w.size(); j++)
		{
			if (t[i] == w[j])
			{
				std::cout << t[i] << " is correct!" << std::endl;
				correct.push_back(true);
			}
		}
	}
	
	if (correct.size() != 6)
	{
		std::cout << "Loser" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Winner!" << std::endl;
		return true;
	}
};