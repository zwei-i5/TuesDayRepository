#pragma once
#include"Sorcerer.h"
using namespace std;

class Megumi:public Sorcerer
{
public:
	Megumi(): Sorcerer(100, 80) {}
	void UseTechnique()override;
};

