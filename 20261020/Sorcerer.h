#pragma once
#include<string>
class Sorcerer
{
protected:
	string name;
	int hp;
	int Cursedpower;
public:
	virtual void ShowStatus();
	virtual void UseTechnique() = 0;
};

