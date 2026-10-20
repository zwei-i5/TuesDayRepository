#pragma once
#include"Config.h"
class Card
{
private:
	int deck[Config::DECK];
	int cardCount;
public:
	Card();
	//カード生成
	void CreateCard();
	//カードのシャッフル
	void ShuffleCard();
	//カードを引く
	int PullCard();
	//残りのカード枚数
	int GetCardCount();
};

