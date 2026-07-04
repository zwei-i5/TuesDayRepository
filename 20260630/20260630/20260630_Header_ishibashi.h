#pragma once
//定数
const int CARD = 11;
const int MAX = 1;
const int MIN = 0;
const int SUM = 21;

enum Pull
{
	Yes,
	No
};
//関数プロトタイプ宣言
int InputCheck();
void Game();
void PullCard();