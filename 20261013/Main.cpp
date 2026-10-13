#include<iostream>
#include"Boss.h"
#include"Enemy.h"
#include"Player.h"
#include"Wizard.h"
#include"BattleManager.h"

using namespace std;

int main(void)
{
	//コンストラクタ
	Player pPlayer("勇者ヨシヒコ");
	Wizard pWizard("魔法使い典子");
	Enemy pEnemy("オオカミ");
	Boss pBoss("魔王");
	BattleManager manager;

	
	manager.StartBattle(&pPlayer);
	manager.StartBattle(&pWizard);
	manager.StartBattle(&pEnemy);
	manager.StartBattle(&pBoss);
		;
	return 0;
}