#include "Enemy.h"
#include<iostream>
using namespace std;

namespace
{
	const int HP = 100;
}
Enemy::Enemy() :hp(HP) {}

Enemy::~Enemy()
{

}

void Enemy::ShowStatus()const
{
	cout << "Enemy HP:" << hp << endl;
}

void Enemy::Takedamege(int damage)
{
	hp -= damage;
	if (hp < 0) hp = 0;
}

int Enemy::GetHp()const
{
	return hp;
}
