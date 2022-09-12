#pragma once
#include"DxLib.h"
#include"player.h"
#include"product.h"

class Player;

class Box
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

	void OnCollisionX();

	void OnCollisionY();

	void HomingCollision();
	
	void	SetPlayer(Player* player_) { player = player_; };

	float	posX;
	float	posY;
	float	width = 240;
	float	higth = 240;
	bool	flag;
	bool	mapFlag;
	bool	moveFlag;
private:
	int	handle;
	float	move;
	float	oldX;
	float	oldY;
	float   x_;
	float	y_;

	Player* player;
};

