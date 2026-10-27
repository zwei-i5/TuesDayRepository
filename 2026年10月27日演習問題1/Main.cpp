#include<iostream>
#include"Enemy.h"
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

const int MAX_HP = 70;
const int MIN_HP = 30;
const int INDEX = 3;
const int MAX_ATTACK = 70;
const int MIN_ATTACK = 20;
int main(void)
{
	//乱数初期化
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<Enemy> enemies;
	//HP生成
	for (int i = 0; i < INDEX; i++)
	{
		int num = rand() % MAX_HP + MIN_HP;
		enemies.push_back(Enemy(num));
	}
	//HPの表示
	for (const Enemy& enemy : enemies)
	{
		enemy.ShowHP();
	}

	//enemies.erase(enemies.begin() + 0);
	/*cout << "1体削除しました。" << endl;*/

	//for (const Enemy& enemy : enemies)
	//{
	//	enemy.ShowHP();
	//}

	cout << "敵の数:" << enemies.size() << endl;

	int doattack = rand() % MAX_ATTACK + MIN_ATTACK;
	int choice;
	cout << "攻撃対象を選んでください。" << endl;
	for (int i = 0; i < enemies.size(); i++)
	{
		cout << i + 1 << "番目の敵：";
		enemies[i].ShowHP();
	}
	cin >> choice;
	if (choice > 0 && choice < enemies.size())
	{
		enemies[choice-1].Damage(doattack);
		cout << choice << "番目の敵に" <<
			doattack << "のダメージ！！" << endl;
		enemies[choice-1].GetHp();
		if (enemies[choice].GetHp() == 0)
		{
			cout << "敵を倒しました。" << endl;
			enemies.erase(enemies.begin() + choice);
		}
		for (const Enemy& enemy : enemies)
		{
			enemy.ShowHP();
		}
	}


	return 0;
}