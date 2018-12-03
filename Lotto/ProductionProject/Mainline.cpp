#include "Production.h"


int main()
{
	Production p;
	std::vector<int> ticket, winningNums;
	ticket = p.takeInput();
	winningNums = p.generateWinners();
	p.checkTicket(ticket, winningNums);
	system("PAUSE");
	return 0;
}
