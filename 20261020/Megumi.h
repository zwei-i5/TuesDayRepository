#pragma once
#include"Sorcerer.h"
using namespace std;

class Megumi:public Sorcerer
{
private:
	int hp = 100;
	int Cursedpower = 80;
public:
	void ShowStatus();
	void UseTechnique()override;
};

