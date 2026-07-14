#pragma once
//入力の最小値
const int PITCHING_MIN = 0;
//入力の最大値
const int PITCHING_MAX = 3;
//確率
const int PROBABILITY = 4;
//ストライクカウントの最大値
const int STRIKE_COUNT = 3;
//ボールカウントの最大値
const int BALL_COUNT = 4;
//アウトカウントの最大値
const int OUT_COUNT = 3;
//ヒットカウントの最大値
const int HIT_COUNT = 4;

//列挙体
enum PitchType
{
	Straight,
	Curve,
	Slider,
	Sinker
};
//球種の表示関数
void PitchingType(int pitching);
//リザルト関数
void Result(int out);
//入力関数
int InputCheck(int min, int max);

