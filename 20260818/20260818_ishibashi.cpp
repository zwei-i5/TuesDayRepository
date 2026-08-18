#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
//定数
const int MAX_CARD = 7;
const int MIN_CARD = 1;
int InputCheck(int min, int max)
{
	int input;
	while (true)
	{
		cin >> input;
		if (min > input || max < input)
		{
			cout << "再入力してください。" << endl;
		}
		else
		{
			break;
		}
	}
	return input;
}
int main()
{
	cout << "===============数あてゲーム===============" << endl;
	//カードの生成
	vector<int> cards;
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cards.push_back(i);
		}
	}
	//カードをシャッフル
	random_device rd;
	mt19937 gen(rd());
	shuffle(cards.begin(), cards.end(), gen);
	vector<int> hidden;//伏せカード
	vector<int> field;//場
	vector<int> player;//手札
	vector<int> cpu;//相手の手札
	//カードを分ける（・伏せ：７枚　・場：７枚　・手札：７枚　・相手の手札：７枚）
	for (int i = 0; i < 7; i++)
	{
		hidden.push_back(cards[i]);
		field.push_back(cards[i + 7]);
		player.push_back(cards[i + 14]);
		cpu.push_back(cards[i + 21]);
	}
	//カードの表示
	cout << "場のカード；";
	for (int card : field)
	{
		cout << card << " ";
	}
	cout << endl;
	cout << "CPUのカード";
	for (int card : cpu)
	{
		cout << card << " ";
	}
	cout << endl;
	//プレイヤーがカードを予想
	bool Published[7] = { false };
	for (int correct = 0; correct < 7; correct++)
	{
		int position,answer;
		cout << "カードを選択して下さい。";
		position = InputCheck(MIN_CARD, MAX_CARD);
		if (Published[position - 1])
		{
			cout << "そのカードはすでに公開されています。\n" <<
				"別のカードを選択してください" << endl;
			correct--;
			continue;
		}
		cout << "予想した数字を入力してください。";
		answer=InputCheck(MIN_CARD, MAX_CARD);
		if (player[position - 1] == answer)
		{
			cout << "正解です！！カードを公開します。\n" <<
				"カードは" << player[position - 1] << "でした。" << endl;
			Published[position - 1] = true;
			for (int i = 0; i < 7; i++)
			{
				if (Published[i])
				{
					cout <<"["<< player[i] << "]";
				}
				else
				{
					cout << "[?]";
				}
			}
			cout << endl;
		}
		else
		{
			cout << "不正解！" << endl;
			correct--;
		}

	}
	cout << "ゲーム終了！！";
	return 0;
}