#pragma once
#include<iostream>
#include<string>
using namespace std;
class Enemy
{
public:
	Enemy(const string name);
	~Enemy();
	int GetHp()const;
	void Draw()const;
	void Damage(int damage);
private:
	string name;
	int hp;
};

