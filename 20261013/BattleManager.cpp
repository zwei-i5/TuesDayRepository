#include "BattleManager.h"
#include<iostream>
using namespace std;

void BattleManager::StartBattle(Character* character)
{

	character->Attack();
}
