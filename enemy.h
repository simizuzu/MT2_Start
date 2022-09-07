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

	float	posX;
	float	posY;
	float	r = 20.0f;
private:
	bool	flag;
	float	move = 3.5f;
	
	

	Player* player = nullptr;
};