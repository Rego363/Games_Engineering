#include <iostream>
#include <vector>

class Character
{
public:
	Character() {};
	virtual ~Character() {};
	virtual void draw() = 0;
};

class Player : public Character
{
public: 
	void draw()
	{
		std::cout << "Draw Player" << std::endl;
	}
};

class Boss : public Character
{
public:
	void draw()
	{
		std::cout << "Draw Boss" << std::endl;
	}
};

class Factory
{
public: 
	virtual Character* CreatePlayer() = 0;
	virtual Character* CreateOpponents() = 0;
};

class CharacterFactory : public Factory
{
public: 
	Character* CreatePlayer()
	{
		return new Player;
	}

	Character* CreateOpponents()
	{
		return new Boss;
	}
};

int main()
{
	Factory* factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->CreatePlayer());
	characters.push_back(factory->CreateOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	system("PAUSE");
}