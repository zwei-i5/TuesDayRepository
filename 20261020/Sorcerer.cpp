#include "Sorcerer.h"
#include<iostream>
#include<string>
using namespace std;

void Sorcerer::ShowStatus()
{
	cout << "体力："<< hp <<  endl;
	cout << "呪力：" << power  <<endl;
}

void Sorcerer::UseTechnique()
{
	cout << "術式を使用" << endl;
}