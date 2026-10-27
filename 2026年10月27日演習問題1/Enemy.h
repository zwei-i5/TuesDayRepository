#pragma once
class Enemy
{
private:
	int hp;
public:
	Enemy(int hp);
	void ShowHP()const;
	~Enemy();
	void Damage(int d);
	int GetHp()const;
};

