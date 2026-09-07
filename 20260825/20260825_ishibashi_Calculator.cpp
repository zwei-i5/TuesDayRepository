#include "20260825_ishibashi_Calculator.h"
#include<iostream>
using namespace std;


void Calculator::add()
{
	cout <<"答え：" << num1 + num2 << endl;
}

void Calculator::subtract()
{
	cout <<"答え：" << num1 - num2 << endl;
}

void Calculator::multply()
{
	cout <<"答え：" << num1 * num2 << endl;
}

void Calculator::divide()
{
	cout <<"答え：" << num1 / num2 << endl;
}

int main()
{
	Calculator calculator;
	while (true)
	{
		//数字を入力
		cout << "数字を入力してください" << endl;
		cin >> calculator.num1;
		cin >> calculator.num2;
		//計算方法の選択
		cout << "計算方法を選択してください。(０：加算、１：減算、２：乗算、３：除算)" << endl;
		while (true)
		{
			cin >> calculator.input;
			if (calculator.input < 0 || calculator.input > 3)
			{
				cout << "再入力してください。" << endl;
			}
			else
			{
				break;
			}
		}
		if (calculator.input == 0)
		{
			calculator.add();
		}
		if (calculator.input == 1)
		{
			calculator.subtract();
		}
		if (calculator.input == 2)
		{
			calculator.multply();
		}
		if (calculator.input == 3)
		{
			calculator.divide();
		}
		cout << "計算を続けますか？" << endl;
		cin >> calculator.cont;
		if (calculator.cont = 0) {}//続ける
		else if (calculator.cont = 1)//終了
		{
			break;
		}
	}
	return 0;
}