#include "Enemy.h"
#include<iostream>
#include<ctime>
using namespace std;

Enemy::Enemy()
{
	this->hp = (rand() % 70) + 30;
}

void Enemy::ShowHP()const
{
	cout << "Enemy HP:" << hp << endl;
}

Enemy::~Enemy() {}