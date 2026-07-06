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
//判定関数
void Judge(int p, int c)
{
	if (p == SUM && c == SUM || p > SUM && c > SUM)
	{
		cout << "引き分け" << endl;
	}
	else if (p == SUM || p < c)
	{
		cout << "プレイヤーの勝利" << endl;
	}
	else if (c == SUM || p > c)
	{
		cout << "CPUの勝利" << endl;
	}
}

//実行関数
void PlayGame()
{
	//変数
	int player = 0, cpu = 0;
	int playcard = 0, cpucard = 0;
	int turn = 0;
	int playsum = 0, cpusum = 0;
	int i;
	int num;
	int turnchange = 0;
	int rf = 0;
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

	//ゲームの開始
	while (playsum < SUM && cpusum < SUM)
	{
		if (rf == 0)
		{
			cout << "================ターン" << turn + 1 << "================\n";
		}
		//もしターンのはじめだったら
		if (turn == 0)
		{
			//50%の確率でプレイヤーまたはCPUにターンを渡す。
			if (rand() % 2 == 0)
			{
				cout << "=====プレイヤーのターン=====\n" << "カードを引くか選択してください\n";
				//カードを引くか選択
				player = InputCheck(MIN, MAX);
				//trueならカードを引く
				if (PullCard(player) == true)
				{
					Switch(player);
					//カードを山札から引く
					num = rand() % CARD + 1;
					//引いたカードを合計に足す
					playsum += num;
					cout << "カードを引きました。\n" << "引いたカード:" << num << "\n" << "現在のカードの合計:" << playsum << "\n";

				}
				else
				{
					cout << "カードを引きませんでした。\n" << "現在のカードの合計:" << playsum << "\n" <<
						"CPUのターンに移ります。\n";
				}
				//ターンの変更
				turnchange = true;
				rf++;
			}
			//50%の確率でプレイヤーまたはCPUにターンを渡す。
			else
			{
				cout << "=====CPUのターン=====\n";
				//もしCPUの合計がプレイヤーより低かったら
				if (cpusum < playsum)
				{
					cout << "CPUがカードを引きました。\n";
					//カードを山札から引く
					cpucard = rand() % CARD + 1;
					//引いたカードを合計に足す
					cpusum += cpucard;
					cout << "CPUが引いたカード:" << cpucard << "\n" <<
						"CPUの現在のカードの合計:" << cpusum << endl;
				}
				else
				{
					cout << "CPUはカードを引きませんでした。\n"
						<< "CPUの現在のカードの合計:" << cpusum << "\n"
						<< "プレイヤーのターンに移ります\n";
				}
				//ターンの変更
				turnchange = false;
				rf--;
			}
		}
		//もしturnchangeがtrueなら
		if (turnchange == true)
		{
			cout << "=====CPUのターン=====\n";
			//もしCPUの合計がプレイヤーより低かったら
			if (cpusum < playsum)
			{
				cout << "CPUがカードを引きました。\n";
				//カードを山札から引く
				cpucard = rand() % CARD + 1;
				//引いたカードを合計に足す
				cpusum += cpucard;
				//表示
				cout << "CPUが引いたカード:" << cpucard << "\n" <<
					"CPUの現在のカードの合計:" << cpusum << endl;
			}
			else
			{
				cout << "CPUはカードを引きませんでした。\n"
					<< "CPUの現在のカードの合計:" << cpusum << "\n"
					<< "プレイヤーのターンに移ります\n";
			}
			//turnchangeをfalseにしてプレイヤーのターンに移る
			turnchange = false;
			rf--;
		}
		else
		{
			//もしturnchangeがfalseなら
			if (turnchange == false)
			{
				cout << "=====プレイヤーのターン=====\n" << "カードを引くか選択してください\n";
				//カードを引くか選択
				player = InputCheck(MIN, MAX);
				//trueならカードを引く
				if (PullCard(player) == true)
				{
					Switch(player);
					//カードを山札から引く
					num = rand() % CARD + 1;
					//引いたカードを合計に足す
					playsum += num;
					//表示
					cout << "カードを引きました。\n" << "引いたカード:" << num << "\n" << "現在のカードの合計:" << playsum << "\n";
				}
				else
				{
					cout << "カードを引きませんでした。\n" << "現在のカードの合計:" << playsum << "\n" <<
						"CPUのターンに移ります。\n";
				}
				
			}
			//turnchangeをtrueにしてCPUのターンに移る
			turnchange = true;
			rf++;
		}
		//ターンを経過させるかどうか
		if (rf == 0)
		{
			cout << "=======途中経過======\n" << "PLAYER:" << playsum << "\n" <<
				"CPU:" << cpusum << "\n";
			turn++;
		}
	}
	//試合結果
	cout << "================試合結果================\n";
	Judge(playsum, cpusum);
}