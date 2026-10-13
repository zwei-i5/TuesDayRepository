#pragma once
#include<string>
class Character
{
public:
	Character(std::string name);
	virtual ~Character() = default;
	std::string Getname();
	virtual void Attack();
};

