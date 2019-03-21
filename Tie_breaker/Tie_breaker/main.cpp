#include <iostream>
#include <thread>
#include <vector>

const int n = 4;
int in[n];
int last[n];

int max(std::vector<int> v)
{
	int largest = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > largest)
		{
			largest = v[i];
		}
	}
	return largest;
}

void cs(int i)
{
	while (true)
	{
		for (int j = 0; j < n; j++)
		{
			/* Entry protocol */
			/* Remember process i is in stage j  and is last */
			in[i] = j;
			last[j] = i;
			for (int  k = 0; k < n ; k++)
			{
				if (i != k)
				{
					/* wait if process k is in higher numbered stage and process i was the last to enter stage j */
					while (in[k] >= in[i] && last[j] == i)
					{
						continue;
					}
				}
			}
		}
		// Critical section;

		std::cout << i << std::endl;
		in[i] = 0;	/* exit protocol */
		//noncritical section;
	}
}

int main()
{
	std::vector<std::thread> m_threads;

	for (int i = 0; i < n; i++)
	{
		m_threads.push_back(std::thread(cs, i));
	}

	for (int i = 0; i < n; i++)
	{
		m_threads[i].join();
	}

	return 0;
}