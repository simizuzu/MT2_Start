#include "DxLib.h"
#include "Vector3.h"
//球の描画
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum,
	const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag);

int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);


// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2C_17_シミズショウ: タイトル";










// ウィンドウ横幅
const int WIN_WIDTH = 1024;

// ウィンドウ縦幅
const int WIN_HEIGHT = 576;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	//クリップ面      近     遠
	SetCameraNearFar(1.0f, 1000.0f);//カメラの有効範囲の設定
	SetCameraScreenCenter(WIN_WIDTH / 2.0f, WIN_HEIGHT / 2.0f);//画面の中心をカメラの中心に合わせる

	SetCameraPositionAndTargetAndUpVec(
		VGet(0.0f, 0.0f, -100.0f),//カメラの位置
		VGet(0.0f, 0.0f, 0.0f),//カメラの注視点
		VGet(0.0f, 1.0f, 0.0f));//カメラの上の向き

	// 画像などのリソースデータの変数宣言と読み込み

	Vector3 position(0, 0, 0);//位置
	Vector3 velocity(0.0f, 0.0f, 0.5f);//速度

	// ゲームループで使う変数の宣言


	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		position += velocity;

		// 描画処理
		ClearDrawScreen();
		DrawSphere3D(position, 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), true);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}

//オーバーロード
//球の描画
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum,
	const unsigned int DifColor, const unsigned int SpcColor, const int FillFlag)
{
	VECTOR centerPos = { CenterPos.x,CenterPos.y,CenterPos.z };

	return DrawSphere3D(centerPos, r, DivNum, DifColor, SpcColor, FillFlag);
}

//線分の描画
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color)
{
	VECTOR p1 = { Pos1.x,Pos1.y,Pos1.z };
	VECTOR p2 = { Pos2.x,Pos2.y,Pos2.z };

	return DrawLine3D(p1, p2, Color);
}
