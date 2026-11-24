#include "GameTask.h"
#include<iostream>
#include<limits>
#include"ConfigTask.h"

void GameTask::Init()
{
	//“G‚Ì”‚¾‚¯¶¬
	for (int i = 0; i < ConfigTask::ENEMY_COUNT; i++)
	{
		enemies.push_back(std::make_shared<EnemyTask>());
	}
}

void GameTask::Draw() const
{
	std::cout << "“G:\n";
	for (int i = 0; i < enemies.size(); i++)
	{
		//“G‚ª¶‚«‚Ä‚¢‚½‚ç
		if (enemies[i] ->IsAlive())
		{
			//Œ»İ‚Ì“G‚ÌHP‚ğ•\¦
			std::cout << "“G" << i + 1 << "HP:" 
				<< enemies[i]->GetHp() << "\n";
		}
		//¶‚«‚Ä‚¢‚È‚©‚Á‚½‚ç
		else
		{
			std::cout << "Œ‚”jÏ‚İ\n";
		}
	}
}

void GameTask::Attack()
{
	int target;
	std::cout << "UŒ‚‚·‚é“G‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢B(1`3)\n";
	//”š‚¾‚¯‚Ìó•t‚ğ‚·‚é
	if (!(std::cin >> target))
	{
		std::cout << "”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

		return;

	}
	//‘I‘ğ‚ª”ÍˆÍŠO‚Ìê‡
	if (target < 1 || target > ConfigTask::ENEMY_COUNT)
	{
		std::cout << "“ü—Í‚µ‚½”š‚Í‘I‘ğo—ˆ‚Ü‚¹‚ñBÄ“x“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
		return;
	}

	std::shared_ptr<EnemyTask> targetEnemy = enemies[target - 1];
	//‘I‘ğ‚µ‚½“G‚ªŒ‚”jÏ‚İ‚Ìê‡
	if (!targetEnemy->IsAlive())
	{
		std::cout << "‚±‚Ì“G‚Í‚·‚Å‚É“|‚³‚ê‚Ä‚¢‚Ü‚·B\n";
		return;
	}
	//“ü—Í¬Œ÷Œã
	std::cout << "UŒ‚‚·‚é“G‚ÍA" << target << "\n";
	//‘I‘ğ‚µ‚½“G‚ÉUŒ‚
	targetEnemy->Damage(ConfigTask::DAMEGE);
	std::cout << "“G" << target << "‚Éí“¬ƒ_ƒ[ƒW" 
		<< ConfigTask::DAMEGE << "‚ğ—^‚¦‚Ü‚µ‚½B\n";

}

bool GameTask::IsGameClear() const
{
	//“G‚ªˆêl‚Å‚à¶‚«‚Ä‚¢‚ê‚Î
	for ( const auto& enemy : enemies)
	{
		if (enemy->IsAlive())
		{
			return false;
		}
	}

	return true;
}
//ƒQ[ƒ€‚ğ“®‚©‚·
void GameTask::Run()
{
	Init();

	while (true)
	{
		Draw();
		Attack();
		if (IsGameClear())
		{
			std::cout << "GamerClear\n";
			break;
		}
	}
}