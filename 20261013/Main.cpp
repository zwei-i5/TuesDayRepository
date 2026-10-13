#include<iostream>
#include"Boss.h"
#include"Enemy.h"
#include"Player.h"
#include"BattleManager.h"

using namespace std;

int main(void)
{
	//コンストラクタ
	Player pPlayer;
	Enemy pEnemy;
	Boss pBoss;
	BattleManager manager;

	
	manager.StartBattle(&pPlayer);
	manager.StartBattle(&pEnemy);
	manager.StartBattle(&pBoss);
		;
	return 0;
}