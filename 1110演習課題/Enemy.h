#pragma once
class Enemy
{
private:
	int hp;
public:
	Enemy();
	~Enemy();
	void ShowStatus()const;
	void Takedamege(int damage);
	int GetHp()const;
};

