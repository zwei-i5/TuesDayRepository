#pragma once
#include"Sorcerer.h"
using namespace std;
class Gojo:public Sorcerer
{
public:
	Gojo() : Sorcerer(999, 999) {}
	void UseTechnique()override;

};

