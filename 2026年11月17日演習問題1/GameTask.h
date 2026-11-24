#pragma once
#include <memory>
#include<vector>
#include "EnemyTask.h"
#include "ConfigTask.h"
class GameTask
{
private:
	std::vector<std::shared_ptr<EnemyTask>> enemies;
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw()const;
	/// <summary>
	/// 攻撃
	/// </summary>
	void Attack();
	/// <summary>
	/// クリア判定
	/// </summary>
	/// <returns></returns>
	bool IsGameClear() const;

public:
	/// <summary>
	/// ゲームプレイ
	/// </summary>
	void Run();
};

