#pragma once
#include"DxLib.h"

class Player
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void	Initialize();
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

	float	x_;
	float	y_;
	float	r;
	float	range;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move;
};