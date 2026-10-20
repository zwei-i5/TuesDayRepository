#include "Card.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


Card::Card()
{
	cardCount = Config::DECK;
}

void Card::CreateCard()
{
	//カードを生成
	int index = 0;
	for (int number = Config::MIN_CARD; number < Config::MAX_CARD + 1; number++)
	{
		for (int i = 0; i < 1; i++)
		{
			deck[index] = number;
			index++;
		}
	
	}
}

void Card::ShuffleCard()
{
	for (int i = Config::DECK-1; i > 0; i--)
	{
		int shuffle = i + rand() % (Config::DECK - i);
		int temp = deck[i];
		deck[i] = deck[shuffle];
		deck[shuffle] = temp;
	}
	////シャッフルされているか確認
	//for (int i = 0; i < Config::DECK; i++)
	//{
	//	cout << deck[i] << endl;
	//}
}


