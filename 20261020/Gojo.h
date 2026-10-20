#pragma once
#include"Sorcerer.h"
using namespace std;
class Gojo:public Sorcerer
{
private:
	int hp = 999;
	int Cursedpower = 999;
public:
	void UseTechnique()override;
};

