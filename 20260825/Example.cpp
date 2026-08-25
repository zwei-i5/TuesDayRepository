#include "Example.h"
#include<iostream>
using namespace std;

void Example::Move()
{
	playerX += 10;
}

void Example::Attack()
{
	cout << "UŒ‚—ÍF" << attack << "UŒ‚‚µ‚Ü‚µ‚½B";
}

void Example::Damage(int damage)
{
	hp -= damage;
	if (hp < 0)
	{
		hp = 0;
	}
}
void Example::ShowStatus()
{
	cout << "HP:" << hp << endl;
	cout << "PlayerXÀ•W" << playerX << endl;
	cout << "PlayerYÀ•W" << playerY << endl;
	cout << "UŒ‚—ÍF" << attack << endl;
}

