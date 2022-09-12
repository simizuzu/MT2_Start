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
	void	Initialize();
	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	State(float	x_, float	y_);
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

	void markCollision();


	float	posX;
	float	posY;
	float	r = 40.0f;
	bool	flag;
	int	bFlag;
	int	markFlag;
private:
	int	handle[4];
	int	hatenaHandle;
	int	bikkuriHandle;
	float	move = 3.0f;

	float	oldX[2];
	float	oldY[2];
	const	int	time = 15;
	int	timer;
	int	num;

	Player* player = nullptr;
};