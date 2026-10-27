#pragma once
#include<string>
class Sorcerer
{
protected:
	
	int hp;
	int power;
public:
	Sorcerer(int h, int p) :hp(h), power(p) {}
	virtual void ShowStatus();
	virtual void UseTechnique() = 0;
};

