#include <iostream>
#include <thread>
#include <vector>

bool in1 = false; 
bool in2 = false;
int last = 1;

void cs1()
{
	while (true)
	{
		in1 = true;
		last = 1;
		/* entry */
		while (in2 && last == 1)
		{
			continue;
		}
		std::cout << "1" << std::endl;
		// critical section;
		in1 = false; /* exit */
		// noncritical section;
	}
}

void cs2()
{
	while (true)
	{
		in2 = true;
		last = 2;
		/* entry */
		while (in1 && last == 2)
		{
			continue;
		}

		std::cout << "2" << std::endl;

		// critical section;
		in2 = false; /* exit */
		// noncritical section;
	}
}


int main()
{
	std::vector<std::thread> m_threads;

	m_threads.push_back(std::thread(cs1));
	m_threads.push_back(std::thread(cs2));

	m_threads[0].join();
	m_threads[1].join();

	system("PAUSE");
	return 0;
}