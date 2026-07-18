#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260714_Header_ishibashi.h"
using namespace std;

int playerselect(int min, int max,bool used[])
{
	//変数
	int select;
	while (true)
	{
		//入力
		cin >> select;
		//間違っていたら
		if (select < min || select > max )
		{
			//再入力
			cout << "範囲外です。再入力してください。\n";
		}
		else if (used[select - 1])
		{
			cout << "使用済み\n";
		}
		//あっていたら
		else
		{
			//ループを抜ける
			used[select - 1] = true;
			return select - 1;
			break;
		}
	}
	return select;
}
int cpuselect(bool used[])
{
	int select;
	do {
		select = rand() % INDEX;
	} while (used[select]);
	used[select] = true;

	return select;
}

void Judge(int pl,int ep,int& pp,int& cp)
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
	cout << "試合結果\n" <<
		p << "　VS　" << c << endl;
	if (p > c)
	{
		cout << "プレイヤーの勝利!!";
	}
	else if (p == c)
	{
		cout << "引き分け";
	}
	else
	{
		cout << "CPUの勝利!!";
	}
}
void Game()
{
	int player[INDEX], cpu[INDEX];
	int p, c;
	int playerpoint = 0, cpupoint = 0;
	int turn = 0;
	int i;
	bool playerused[INDEX] = { false };
	bool cpuused[INDEX] = { false };
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
	
	while (turn < TURN_COUNT)
	{
		//入力
		cout << "手持ちから一つ数字を選択して下さい。\n";
		int p = playerselect(INPUT_MIN,INPUT_MAX,playerused);
		int c = cpuselect(cpuused);

		cout << player[p] << " VS " << cpu[c] << endl;
		Judge(player[p], cpu[c], playerpoint, cpupoint);
		cout << "PLAYER:" << playerpoint << "点\n";
		cout << "CPU:" << cpupoint << "点\n";
		turn++;
	}
	Result(playerpoint, cpupoint);
}