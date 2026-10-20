#include "Chip.h"
#include<iostream>
using namespace std;

Chip::Chip()
{
	chipCount = Config::CHIP;
}

void Chip::CreateChip()
{
	int index = 0;
	for (int chipnum = 0; chipnum < Config::CHIP; chipnum++)
	{
		chip[index] = chipnum;
		index++;
	}
}

void Chip::UseChip()
{
	int nowchip = chip[0];
	for (int i = 0; i < chipCount; i--)
	{
		chip[i] = chip[i + 1];
	}
	chipCount--;
	cout << "残りのチップ数：" << chipCount << endl;
}

int Chip::GetChipCount()
{
	return chipCount;
}
