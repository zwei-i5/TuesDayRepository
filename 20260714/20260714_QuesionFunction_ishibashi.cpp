#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260714_QuesionHeader_ishibashi.h"
using namespace std;

//球種の呼び出し関数
void PitchingType(int pitching)
{
    switch (pitching)
    {
    case Straight://０
        cout << "ストレート" << endl;
        break;

    case Curve://１
        cout << "カーブ" << endl;
        break;

    case Slider://２
        cout << "スライダー" << endl;
        break;

    case Sinker://３
        cout << "シンカー" << endl;
        break;
    }
}
//リザルト関数
void Result(int out)
{
    //もしアウトカウントがOUTCOUNTより大きくなったら
    if (out >= OUT_COUNT)
    {
        //表示
        cout << "PLAYER WINNER!!" << endl;
    }
    //そうではなかったら
    else
    {
        //表示
        cout << "CPU WINNER!!" << endl;
    }
}
//入力関数
int InputCheck(int min, int max)
{
    //変数
    int player;
    while (true)
    {
        //入力
        cin >> player;
        //もし誤りがあったら
        if (player < PITCHING_MIN || player > PITCHING_MAX)
        {
            //再入力
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }
        //誤りがなければ
        else
        {
            //ループから抜ける
            break;
        }
    }
   //プレイヤー返す
    return player;
}