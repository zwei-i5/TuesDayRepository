#include<iostream>
#include"20260818_Prac1_ishibashi.h"
using namespace std;
void Damage(int* d)
{
	*d = *d-DAMAGE;
	cout << "‚Q‚Oƒ_ƒ[ƒW‚ðŽó‚¯‚½" << endl;
}
void Heal(int* h)
{
	*h = *h+HEAL;
	cout << "HP‚ð‚R‚O‰ñ•œ‚µ‚½" << endl;
}
void MainGame()
{
	int hp = 100;
	Damage(&hp);
	cout << hp << endl;;
	Heal(&hp);
	cout << hp;
}