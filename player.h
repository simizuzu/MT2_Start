#pragma once
#include"DxLib.h"

class Player
{
public:

	/// <summary>
	/// ゲーム内の初期化
	/// </summary>
	void	State();
	/// <summary>
	/// 更新
	/// </summary>
	void	Update(char	key[],char	oldkey[]);
	/// <summary>
	/// 描画
	/// </summary>
	void	Draw();

	void OnCollision();

	float	x_;
	float	y_;
	const	float	r = 20.0f;;
	const	float	range = 120.0f;
	float	scrollX;
	float	scrollY;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move = 5.0f;
};