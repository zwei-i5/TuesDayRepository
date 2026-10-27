#include<iostream>
#include"Gojo.h"
#include"Inumaki.h"
#include"Megumi.h"
using namespace std;

int main()
{
	Megumi megumi;
	Inumaki inumaki;
	Gojo gojo;
	
	Sorcerer* character[3] = { &megumi,&inumaki,&gojo };

	for (Sorcerer * c : character)
	{
		c->ShowStatus();
		c->UseTechnique();
		cout << "=========================\n";
	}


	return 0;
}