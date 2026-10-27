#pragma once
#include"Sorcerer.h"
using namespace std;
class Inumaki:public Sorcerer
{
public:
	Inumaki() : Sorcerer(90, 70) {}
	void UseTechnique()override;

};

