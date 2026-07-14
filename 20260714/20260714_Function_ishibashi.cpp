#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260714_Header_ishibashi.h"
using namespace std;

int InputCheck(int min, int max)
{
	//変数
	int input;
	while (true)
	{
		//入力
		cin >> input;
		//間違っていたら
		if (INPUT_MIN > input || INPUT_MAX < input)
		{
			//再入力
			cout << "範囲外です。再入力してください。\n";
		}
		//あっていたら
		else
		{
			//ループを抜ける
			break;
		}
	}
	return input;
}
void SW(int choice[])
{
	switch (choice[10] - 1)
	{
	case 0:
		cout << choice[0];
		break;
	case 1:
		cout << choice[1];
		break;
	case 2:
		cout << choice[2];
		break;
	case 3:
		cout << choice[3];
		break;
	case 4:
		cout << choice[4];
		break;
	case 5:
		cout << choice[5];
		break;
	case 6:
		cout << choice[6];
		break;
	case 7:
		cout << choice[7];
		break;
	case 8:
		cout << choice[8];
		break;
	case 9:
		cout << choice[9];
		break;
	}

}
void Judge(int pl,int ep,int pp,int cp)
{
	if (pl > ep)
	{
		pp += WIN_POINT;
		cout << "\nプレイヤーの勝利!!\n";
	}
	else if (pl < ep)
	{
		cp += WIN_POINT;
		cout << "\nCPUの勝利!!\n";
	}
	else if (pl == ep)
	{
		pp++;
		cp++;
		cout << "\nDRAW\n";
	}
}
void Result(int p, int c)
{

}
void Game()
{
	int player[10], cpu[10];
	int playerpoint = 0, cpupoint = 0;
	int turn = 0;
	int i, j;
	//乱数初期化
	srand((unsigned int)time(NULL));
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝数字ゲーム＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n" << 
			"ランダムに配布された数字を一つ選択し、相手の選択した数字と比べるゲームです。\n";
	//数字を配布
	cout << "PLAYER：";
	for (i = 0; i < INDEX; i++)
	{
		player[i] = rand() % NUMMAX;
		cout << player[i] << " ";
	}
	cout << "\nCPU：";
	for (i = 0; i < INDEX; i++)
	{
		cpu[i] = rand() % NUMMAX;
		cout << cpu[i] << " ";
	}
	
	while (turn <= TURN_COUNT)
	{
		//入力
		cout << "手持ちから一つ数字を選択して下さい。\n";
		
		player[i] = InputCheck(INPUT_MIN, INPUT_MAX);	
		cpu[i] = rand() % INDEX;
		SW(player); cout << " VS "; SW(cpu);
		Judge(player[10], cpu[10], playerpoint, cpupoint);
		cout << "プレイヤーの得点：" << playerpoint << "\n"
			<< "CPUの得点：" << cpupoint << endl;

		turn++;
	}
}