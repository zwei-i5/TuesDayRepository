#include "Sorcerer.h"
#include<iostream>
using namespace std;

void Sorcerer::ShowStatus()
{
	cout <<
	cout << "体力：" << &hp << endl;
	cout << "呪力：" << &Cursedpower << endl;
}

void Sorcerer::UseTechnique()
{
	cout << "術式を使用" << endl;
}