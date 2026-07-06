#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260630_Header_ishibashi.h"

using namespace std;
//入力チェック
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
//カードを引くかどうか
bool PullCard(int input)
{
	if (input == 0)
	{
		return true;
		
	}
	else if(input == 1)
	{
		return false;
	}
	return false;
}
void Switch(int num)
{
	switch(num)
	{
	case Yes:
		cout << "Yes\n";
		break;
	case No:
		cout << "No\n";
		break;
	default:
		break;
	}
	
}
//ゲーム
void PlayGame()
{
	//変数
	int player = 0, cpu = 0;
	int playcard = 0, cpucard = 0;
	int turn = 0;
	int playsum = 0, cpusum = 0;
	int i;
	int num;
	int turnchage = 0;
	//乱数の初期化
	srand((unsigned)time(NULL));
	//プレイヤーカード配布
	cout << "============簡易版ブラックジャック============\n";
	cout << "PLAYERのカード\n";
	for (i = 0;i < 2;i++)
	{
		//カードを生成
		playcard = rand() % CARD + 1;
		cout << i + 1 << "枚目:" << playcard << "\n";
		//合計に代入
		playsum += playcard;
	}
	//CPUカード配布
	cout << "CPUのカード\n";
	for (i = 0;i < 2;i++)
	{
		//カードの生成
		cpucard = rand() % CARD + 1;
		cout << i + 1 << "枚目:" << cpucard << "\n";
		//カードを合計に代入
		cpusum += cpucard;
	}
	cout << "PLAYER:" << playsum << "\n";
	cout << "CPU:" << cpusum << "\n";

	
	while(playsum < SUM&&cpusum < SUM)
		if (turn == 0)
		{
			//50%の確率でプレイヤーまたはCPUにターンを渡す。
			if (rand() % 2 == 0)
			{
				cout << "=====プレイヤーのターン=====\n" << "カードを引くか選択してください\n";
				player = InputCheck(MIN, MAX);
				if (PullCard(player) == true)
				{
					Switch(player);
					num = rand() % CARD + 1;
					playsum += num;
					cout << "現在のカードの合計:" << playsum << endl;
				}
			}
			else
			{
				cout << "=====CPUのターン=====\n";
				if (cpusum < playsum)
				{
					cout << "CPUがカードを引きました。\n";
					cpucard = rand() % CARD + 1;
					cpusum += cpucard;
					cout << "CPUが引いたカード:" << cpucard;

				}
			}
			turn++;
			break;
		}
}