#pragma once
//定数
const int INDEX = 10;
const int NUMMAX = 51;
const int INPUT_MIN = 1;
const int INPUT_MAX = 10;
const int WIN_POINT = 3;
const int DRAW_POINT = 1;
const int TURN_COUNT = 7;

//関数プロトタイプ宣言
//入力関数
int InputCheck(int min, int max);
//判定関数
void Judge(int pl, int ep, int pp, int cp);
//リザルト関数
void Result(int p,int c);
//実行関数
void Game();
//配列呼び出し
void SW(int choice[]);
