#include "Game.h"
#include"Enemy.h"
#include<iostream>
#include<memory>

void Game::Pointer()
{
	cout << "\n==========通常のポインタ==========\n";

	//オブジェクト
	Enemy enemy1("スライム");
	Enemy enemy2("ドラゴン");
	//オブジェクトのアドレスを取得
	Enemy* target = &enemy1;
	//ポインタを使って操作
	target->Draw();

	//ターゲットをenemy2に切り替えた
	target = &enemy2;

	target->Draw();
	target->Damage(50);
}

void Game::Unique()
{
	cout << "\n==========unique_ptr==========\n";
	//Enemy生成
	unique_ptr<Enemy>enemy1 = make_unique<Enemy>("ゴブリン");
	enemy1->Draw();
	//所有権を移動
	unique_ptr<Enemy>enemy2 = move(enemy1);

	cout << "所有権を移動" << endl;
	if (enemy1 == nullptr)
	{
		cout << "enemy1は空っぽです" << endl;
	}

	enemy2->Draw();
	enemy2->Damage(70);
}
	void Game::Shared()
	{
		std::cout << "\n===== shared_ptr =====\n";
		std::shared_ptr<Enemy> enemy1 = std::make_shared<Enemy>("オーク");
		std::cout << "所有者数" << enemy1.use_count() << std::endl;

		//所有権を共有する
		std::shared_ptr<Enemy>enemy2 = enemy1;
		std::cout << "所有者数" << enemy2.use_count() << std::endl;

		enemy1->Damage(20);
		enemy2->Draw();
		//Enemy2を削除
		enemy2.reset();

		std::cout << "所有者数" << enemy1.use_count() << std::endl;
	}

	void Game::Run()
	{
		Pointer();
		Unique();
		Shared();
	}
}

