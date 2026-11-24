#include "EnemyTask.h"
#include "ConfigTask.h"

EnemyTask::EnemyTask() :hp(ConfigTask::ENEMY_HP) {}//hp‚É‰Šú’l‚ğ‘ã“ü
EnemyTask::~EnemyTask(){}


void EnemyTask::Damage(int damage)
{
	hp -= damage;
	//hp‚ª0‚æ‚è‰º‚É‚È‚Á‚½‚ç
	if (hp < 0)
	{
		//0‚ğ‘ã“ü
		hp = 0;
	}
}

int EnemyTask::GetHp() const
{
	//hp‚ğæ“¾
	return hp;
}

bool EnemyTask::IsAlive() const
{
	//0ˆÈã
	return hp > 0;
}