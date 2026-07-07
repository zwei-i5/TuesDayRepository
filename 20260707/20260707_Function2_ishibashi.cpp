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
//判定関数
void Judge()
{

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

	for (int i = 0; i < 3; i++)
	{
		//確認用
		cout << Hand[i] << " ";
	}
}
void PlayGame()
{
	//変数
	int player = 0, cpu = 0;
	int playHand[3] = {}, cpuHand[3] = {};
	int hitflag = 0;
	int usenum[3] = {};
	//乱数初期化
	srand((unsigned int)time(NULL));
	cout << "==========数字あてゲーム==========\n";
	//手札の生成(プレイヤー)
	cout << "PLAYER:"; Card(playHand);
	cout << "\n";
	//手札の生成（CPU）
	cout << "CPU:"; Card(cpuHand);

	
}
