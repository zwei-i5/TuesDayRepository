#include "Enemy.h"
#include<iostream>

using namespace std;

Enemy::Enemy(int hp)
{
	this->hp = hp;
}

void Enemy::ShowHP()const
{
	cout << "Enemy HP:" << hp << endl;
}

Enemy::~Enemy() {}

void Enemy::Damage(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
	
}

int Enemy::GetHp()const
{
	return hp;
}