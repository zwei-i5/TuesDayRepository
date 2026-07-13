#include<iostream>
#include"20260707_Header2_ishibashi.h"
#include<ctime>
#include<cstdlib>
using namespace std;

//入力関数
int InputCheck(int min, int max)
{
	int input;
	while (true)
	{
		cin >> input;
		if (min > input || max < input)
		{
			cout << "再入力してください。\n";
		}
		else
		{
			break;
		}
	}
	return input;
}
//カード配布関数
void Card(int Hand[])
{
	//手札の生成(プレイヤー)
	for (int i = 0; i < INDEX; i++)
	{
		Hand[i] = rand() % NUM;

		for (int j = 0; j < i; j++)
		{
			if (Hand[i] == Hand[j])   // 重複していたら
			{
				i--;    // この位置をやり直す
				break;
			}
		}
	}

	for (int i = 0; i < INDEX; i++)
	{
		//確認用
		cout << Hand[i] << " ";
	}
}
void PlayGame()
{
	//変数
	int player[INDEX], cpu[INDEX];
	int playHand[INDEX] = {}, cpuHand[INDEX] = {};
	bool playerWinFlag = false,cpuWinFlag = false;
	int hitf=0 ,blowf= 0;
	int i, j;
	//乱数初期化
	srand((unsigned int)time(NULL));
	cout << "==========数字あてゲーム==========\n";
	//手札の生成(プレイヤー)
	cout << "PLAYER:"; Card(playHand);
	cout << "\n";
	//手札の生成（CPU）
	cout << "CPU:"; Card(cpuHand);
	cout << endl;
	while (!playerWinFlag && !cpuWinFlag)
	{
		//プレイヤーのターン
		cout << "==========プレイヤーターン==========\n" << "数字を３つ入力してください\n";
		for (i = 0; i < INDEX; i++)
		{
			player[i] = InputCheck(MIN, MAX);
		}
		
		for (i = 0; i < INDEX; i++)
		{
			for (j = 0; j < INDEX; j++)
			{
				if (player[i] == cpuHand[j])
				{
					if (i == j)
					{
						hitf++;
					}
					else
					{
						blowf++;
					}
				}
				
			}
		}
		cout << "Hit：" << hitf << " " << "Miss" << blowf << endl;
		if (hitf == WIN)
		{
			cout << "BING!!\n";
			playerWinFlag = true;
			break;
		}
		
		//CPUのターン
		cout << "==========CPUのターン==========\n" << "CPUが入力した数字\n";
		for (int i = 0; i < INDEX; i++)
		{
			cpu[i] = rand() % NUM;
			cout << cpu[i] << " ";
		}
		hitf = 0; blowf = 0;
		for (i = 0; i < INDEX; i++)
		{
			for (j = 0; j < INDEX; j++)
			{
				if (cpu[i] == playHand[j])
				{
					if (i == j)
					{
						hitf++;
					}
					else
					{
						blowf++;
					}
				}

			}
		}
		cout << endl;
		cout << "Hit：" << hitf << " " << "Miss" << blowf << endl;
		if (hitf == WIN)
		{
			cout << "BING!!\n";
			cpuWinFlag = true;
			break;
		}
		hitf = 0; blowf = 0;
	}
	if (playerWinFlag)
	{
		cout << "PLAYER WIN!!\n";
	}
	else if (cpuWinFlag)
	{
		cout << "CPU WIN!!\n";
	}
}
