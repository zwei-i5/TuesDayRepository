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
			cout << "再入力してください。\n";
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
void PlayGame()
{
	//変数
	int player = 0, cpu = 0;
	int turn = 0;
	int playsum = 0, cpusum = 0;
	int i;
	//乱数の初期化
	srand((unsigned)time(NULL));
	//プレイヤーカード配布
	cout << "PLAYERのカード\n";
	for (i = 0;i < 2;i++)
	{
		player = rand() % CARD + 1;
		cout << i + 1 << "枚目:" << player << "\n";
		playsum += player;
	}
	//CPUカード配布
	cout << "CPUのカード\n";
	for (i = 0;i < 2;i++)
	{
		cpu = rand() % CARD + 1;
		cout << i + 1 << "枚目:" << cpu << "\n";
		cpusum += cpu;
	}
	cout << "PLAYER:" << playsum << "\n";
	cout << "CPU:" << cpusum << "\n";
}