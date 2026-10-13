#include "BattleManager.h"
#include<iostream>
using namespace std;

void BattleManager::StartBattle(Character* character)
{
	cout << character->Getname() << endl;
	character->Attack();
}
