#include<iostream>
using namespace std;

void ShowArray(int ary[], int index);
void Class(int ary[], int index);
int AddArray(int ary[], int index);

int main()
{
	int input;
	int ary[10];
	input = AddArray(ary, 10);
	cout << "•\Ž¦••ª—Þ•ª‚¯\n";
	ShowArray(ary, 10);
	return 0;
}
//•\Ž¦ŠÖ”
void ShowArray(int ary[], int index)
{
	for (int i = 0; i < 10; i++)
	{
		if (ary[i] % 2 == 0)
		{
			cout << ary[i] << ":‹ô”\n";
		}
		else
		{
			cout << ary[i] << ":Šï”\n";
		}
	}
}
//
int AddArray(int ary[],int index)
{ 
	cout << "”Žš‚ð‚P‚OŒÂ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
	for (int i = 0; i < 10; i++)
	{
		
		while (true)
		{
			cin >> ary[i];
			if (0 > ary[i])
			{
				cout << "Ä“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n";
			}
			else
			{
				break;
			}
		}
	}
	return ary[10];
}