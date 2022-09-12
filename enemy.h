#pragma once
#include"DxLib.h"
#include"product.h"
#include"player.h"

class Player;


class Enemy
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize(float	x_, float	y_);
	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	State();
	/// <summary>
	/// 更新
	/// </summary>
	void	Update();
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void	SetPlayer(Player* player_) {  player = player_; };

	void OnCollision();

	void OnCollisionX();
	void OnCollisionY();
	void OnCollisionX2();
	void OnCollisionY2();

	void OnCollisionXY();

	void	DeathCollision();

	float	posX;
	float	posY;
	float	r = 40.0f;
	bool	flag;
	int	bFlag;
private:
	float	move = 3.0f;

	float	oldX[2];
	float	oldY[2];

	Player* player = nullptr;
};