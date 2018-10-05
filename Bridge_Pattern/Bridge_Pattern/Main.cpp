#include <iostream>

class DrawAPI
{
public:
	virtual void Draw() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void Draw()
	{
		std::cout << "Draw Impl" << std::endl;
	}
};

class Character
{
public: 
	Character() {};
	//void Print() { std::cout << "Printing Character" << std::endl; };

	// Page 2
	virtual void Draw() = 0;
};

class HandleToCharacter
{
public:
	//HandleToCharacter() : character(new Character()) {};
	Character* operator->() { return character; } // Overloaded

private:
	Character* character;
};

class Player : public Character
{
public:
	Player(DrawAPI * api) { this->api = api; }
	void Draw() { api->Draw(); }

private:
	DrawAPI * api;
};

int main(void)
{
	// Page 1
	//HandleToCharacter handle;
	//handle->Print();

	// Page 2
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	
	std::cin.get();
}