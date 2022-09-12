#pragma once
#include"DxLib.h"
#include"player.h"

class Player;

class Goal
{
public:
	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	Initialize();
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

	void	SetPlayer(Player* player_) { player = player_; };

	void OnCollision();

	const	float	w = 192.0f;
	const	float	h = 384.0f;
	bool	flag;
	float	posX;
	float	posY;

private:
	Player* player;
	int	handle;
	const	int	time = 15;
	int	timer;
	int	num;
};

