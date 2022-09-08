#include"gamescene.h"
#include"DxLib.h"

GameScene::GameScene()
{
}

GameScene::~GameScene() {
	delete	player;
	delete	enemy;
	delete	map;
};

void GameScene::Initialize() {
	player = new Player();
	enemy = new	Enemy();
	map = new	Map();
	map->Initialize();
	groundHandle = LoadGraph("./Resources/backGround.png");
}

void GameScene::Update() {

	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
	//---------  ここからにプログラムを記述  ---------//
	switch (scene)
	{
		// タイトル
	case 0:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 1;
			player->State();
			enemy->Initialize(650, 1420);
			enemy->SetPlayer(player);
			map->SetPlayer(player);
		}
		break;

		// 操作説明
	case 1:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 2;
		}
		break;

		// ゲーム
	case 2:
		CheckAll();
		player->Update(keys, oldkeys);
		enemy->Update();
		map->Update();

		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 3;
		}
		break;

		// リザルト(クリア)
	case 3:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
		}
		break;

		// リザルト(ゲームオーバー)
	case 4:
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
		{
			scene = 0;
		}
		break;
	}
}

void	GameScene::Draw() {
	unsigned int color = GetColor(255, 255, 255);
	switch (scene)
	{
		// タイトル
	case 0:
		DrawFormatString(0, 0, color, "タイトル");
	
		break;

		// 操作説明
	case 1:
		DrawFormatString(0, 0, color, " 操作説明");
		break;

		// ゲーム
	case 2:
		DrawGraph(0-player->scrollX, 0 - player->scrollY, groundHandle, true);
		player->Draw();
		enemy->Draw();
		map->Draw();
		DrawFormatString(0, 0, color, "ゲーム");
		break;

		// リザルト(クリア)
	case 3:
		DrawFormatString(0, 0, color, "クリア");
		break;

		// リザルト(ゲームオーバー)
	case 4:
		DrawFormatString(0, 0, color, "オーバー");
		break;
	}
	DrawFormatString(0, 30, color, "scene = %d", scene);
}

void	GameScene::CheckAll() {
	float	x1_ = player->x_;
	float	y1_ = player->y_;
	float	r1_;
	float	x2_;
	float	y2_;
	float	r2_;
	//敵と吸い込む範囲の当たり判定
	{
		r1_=player->range;
		x2_=enemy->posX;
		y2_=enemy->posY;
		r2_=enemy->r;
		if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
		{
			enemy->OnCollision();
		}
	}
	//敵と自機の当たり判定
	{
		r1_ = player->r;
		x2_ = enemy->posX;
		y2_ = enemy->posY;
		r2_ = enemy->r;
		if (CheckCircle(x1_, y1_, r1_, x2_, y2_, r2_))
		{
			player->OnCollision();
		}

	}
}