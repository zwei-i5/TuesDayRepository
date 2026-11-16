#include<iostream>
#include<memory>
#include<vector>
#include"Enemy.h"
using namespace std;

namespace
{
	const int INDEX = 3;
	const int DAMAGE = 30;
}

int main(void)
{
	/*unique_ptr<Enemy>enemy = make_unique<Enemy>();
	enemy->ShowStatus();*/
	vector < unique_ptr<Enemy>> enemies;

	for (int i = 0; i < INDEX; i++)
	{
		enemies.push_back(make_unique <Enemy>());
	}
	while (true)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->ShowStatus();
		}

		int choice;

		cout << "攻撃する対象を選んでください。" << endl;
		cin >> choice;

		if (choice >= 1 && choice <= enemies.size())
		{
			enemies[choice - 1]->Takedamege(DAMAGE);
			enemies[choice - 1]->GetHp();
			if (enemies[choice - 1]->GetHp() == 0)
			{
				enemies.erase(enemies.begin() + choice-1);
			}
		}
		else
		{
			cout << "もう一度入力してください。" << endl;
		}
		
	}

	return 0;
}