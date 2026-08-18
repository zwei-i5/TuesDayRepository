#include<iostream>
using namespace std;

/// <summary>
/// ダメージ関数
/// </summary>
/// <param name="hp"></param>
void Damage(int* hp)
{
	*hp -= 20;
}
/// <summary>
/// ヒール関数
/// </summary>
/// <param name="hp"></param>
void Heal(int* hp)
{
	*hp += 30;
}
int main()
{
	//変数
	int hp = 100;
	//ポインターを渡す
	int* php = &hp;
	cout << "HP:" << *php << endl;
	Damage(&hp);
	cout << "HP:" << *php << endl;
	Heal(&hp);
	cout<< "HP:" << *php << endl;

	return 0;
}
