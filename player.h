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

	void	MapCollisionX();

	void	MapCollisionY();

	float	x_;
	float	y_;
	float	oldX;
	float	oldY;
	const	float	r = 20.0f;;
	const	float	range = 145.0f;
	float	scrollX;
	float	scrollY;
	float	oldScrollX;
	float	oldScrollY;

private:
	float	posX;
	float	posY;
	bool	flag;
	float	move;
};