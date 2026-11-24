#pragma once
class EnemyTask
{
private:
	int hp;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	EnemyTask();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~EnemyTask();
	/// <summary>
	/// 与えるダメージ
	/// </summary>
	/// <param name="damage">ダメージ</param>
	void Damage(int damage);
	/// <summary>
	///	HP取得
	/// </summary>
	/// <returns></returns>
	int GetHp()const;
	/// <summary>
	/// 生き残り判定
	/// </summary>
	/// <returns></returns>
	bool IsAlive() const;
};

