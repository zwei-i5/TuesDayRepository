#pragma once
#include"Sorcerer.h"
using namespace std;
class Inumaki:public Sorcerer
{
private:
	int hp = 90;
	int Cursedpower = 70;
public:	
	void UseTechnique()override;

};

