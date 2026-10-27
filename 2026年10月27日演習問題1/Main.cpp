#include<iostream>
#include"Enemy.h"
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int main(void)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<Enemy> enemies;
	enemies.push_back(Enemy());
	enemies.push_back(Enemy());
	enemies.push_back(Enemy());
	for (const Enemy& enemy : enemies)
	{
		enemy.ShowHP();
	}
	cout << "“G‚Ì”:" << enemies.size() << endl;
	return 0;
}