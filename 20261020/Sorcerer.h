#pragma once
#include<string>
class Sorcerer
{
private:
	string name;
public:
	virtual void ShowStatus();
	virtual void UseTechnique() = 0;
};

