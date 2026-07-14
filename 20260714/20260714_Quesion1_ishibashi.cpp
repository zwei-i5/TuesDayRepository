#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_QuesionHeader_ishibashi.h"
using namespace std;


//====================================
// メイン
//====================================
int main()
{
    //変数
    int player;
    int cpu;
    int probability;

    int strike = 0;
    int ball = 0;
    int out = 0;
    int hit = 0;
    //乱数初期k化
    srand((unsigned int)time(nullptr));

    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;
    //球種の表示
    do
    {
        cout << endl;
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート" << endl;
        cout << "1:カーブ" << endl;
        cout << "2:スライダー" << endl;
        cout << "3:シンカー" << endl;

        player = InputCheck(PITCHING_MIN, PITCHING_MAX);//引数としてMINとMAXを渡す
        //入力
        PitchingType(player);
        //CPUの数字生成
        cpu = rand() % PROBABILITY;

        probability = rand() % PROBABILITY;

        //もしプレイヤーとCPUの数字が違うとき
        if (player != cpu)
        {
            //２５％の確率でボール
            if (probability == 0)
            {
                cout << "ボール！" << endl;
                ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                strike++;
            }
        }
        //プレイヤーとCPUの数字が一致しているとき
        else
        {
            //カウントの初期化（ストライクとボール）
            strike = 0;
            ball = 0;
            //２５％の確率でアウト
            if (probability == 1)
            {
                cout << "OUT!!" << endl;
                //アウトを増やす
                out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                //ヒットを増やす
                hit++;
            }
        }

        //もしストライクカウントが３または、ボールカウントが４になったとき
        if (strike >= STRIKE_COUNT || ball >= BALL_COUNT)
        {
            //ストライクカウントが３だったら
            if (strike >= STRIKE_COUNT)
            {
                cout << "三振アウト！" << endl;
               //アウトをふやす
                out++;
            }
            //ボールカウントが４だったら
            else
            {
                cout << "フォアボール！" << endl;
                //ヒットを増やす
                hit++;
            }
            //カウントの初期化
            strike = 0;
            ball = 0;
        }
        //カウントの表示
        cout << endl;
        cout << "B : " << ball << endl;
        cout << "S : " << strike << endl;
        cout << "O : " << out << endl;
        cout << "Runner : " << hit << endl;

    } while (out < OUT_COUNT && hit < HIT_COUNT);//アウトカウント３以下、ヒットカウントが４以下を満たしているときはループを回す
    //リザルトを表示
    Result(out);

    return 0;
}