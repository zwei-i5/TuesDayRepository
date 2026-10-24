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

	for (int i = 0; i < 3; i++)
	{
		character[i]->ShowStatus();
		character[i]->UseTechnique();
	}


	return 0;
}