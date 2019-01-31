#include <iostream>
#include <thread>

class Shared {
	// This is a shared object between two processes
public:
	int resources = 0;
	void increment() { resources++; }		// Simple increment
	int getValue() { return resources; }	// Get the value
};

class NPC : public std::thread {
private:
	Shared s;

public:
	NPC(Shared _s) {
		s = _s;
	}

	void run()
	{
		while (true)
		{
			std::cout << "NPC..." << s.getValue() << std::endl;
			s.increment();
		}
	}
};

class Player : public std::thread {
private:
	Shared s;

public: 
	Player(Shared _s)
	{
		s = _s;
	}

	void run()
	{
		while (true)
		{
			std::cout << "Player..." << s.getValue() << std::endl;
			s.increment();
		}
	}
};

int main()
{
	Shared * share = new Shared();

	Player * p = new Player(*share);	// Create player

	p->join();	// Start player thread

	NPC * npc = new NPC(*share);	// Create NPC

	npc->join();	// Start NPC thread

	return 0;
}

