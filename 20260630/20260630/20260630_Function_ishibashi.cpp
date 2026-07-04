#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260630_Header_ishibashi.h"

using namespace std;

int InputCheck(int min, int max)
{
	int player;
	while (true)
	{
		cin >> player;
		if (player<min || player>max)
		{
			cout << "Ä“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
		}
		else
		{
			break;
		}
	}
	return player;
}
void PullCard(int input)
{
	int num;
	input = InputCheck(MIN, MAX);
	if (input == 1)
	{
		num = rand() % CARD;
	}
}