#include "DxLib.h"
#include "Vector3.h"

//Vector3型を利用しやすくするための オーバーロード関数群
//球の描画
//DxLib = > int DrawSphere3D(VECTOR Centerpos, float r, int DivNum, unsigned int DifColor, unsigned int Spccolor, int FillFlag);
int DrawSphere3D(const Vector3& CenterPos, const float r, const int DivNum, const unsigned int Difcolor, const unsigned int Spccolor, const int FillFlag);

//線分の描画
// DxLib => int DrawLine3D(VECTOR Pos1, VECTOR Pos2, unsigned int Color);
int DrawLine3D(const Vector3& Pos1, const Vector3& Pos2, const unsigned int Color);

// カメラの位置と姿勢の設定
// DxLib => int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//カメラの位置 
	const Vector3& cameraTarget,//カメラの注視点
	const Vector3& cameraUp //カメラの上の向き
);


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
	SetBackgroundColor(0x00, 0x00, 0x64);

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

	Vector3 cameraPosition(0.0f, 0.0f, -30.0f);
	Vector3 cameraTarget(0.0f, 0.0f, 0.0f);
	Vector3 cameraUp(0.0f, 1.0f, 0.0f);

	SetCameraPositionAndTargetAndUpVec(
		cameraPosition,			//カメラの位置
		cameraTarget,			//カメラの注視点
		cameraUp				//カメラの上の向き
	);

	Vector3 A(3, -1, 2);
	Vector3 B(1, 5, -4);
	Vector3 C(-1, 7, 6);

	Vector3 AB = B - A;//ABベクトルの生成
	Vector3 BC = C - B;// BCベクトルの生成
	Vector3 n = AB.cross(BC);//法線ベクトルを求める(ABベクトルとBCベクトルの外積を求める)
	n.normalize();//法線ベクトルの単位ベクトル化


	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言


	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

		Vector3 v = cameraTarget - cameraPosition;//視点への方向ベクトルを求める(重心→カメラ位置 へのベクトル)
		v.normalize();//単位ベクトル化
		unsigned color = GetColor(255, 255, 255);
		float fv = v.dot(n);
		if (fv > 0)
		{
			color = GetColor(255, 0, 0);
		}

		// 描画処理
		
		// 描画
		ClearDrawScreen(); // 画面を消去
		DrawLine3D(A, B, color);
		DrawLine3D(B, C, color);
		DrawLine3D(C, A, color);

		// 法線の視覚化
		DrawLine3D(A, A + n, GetColor(0, 255, 0));
		DrawLine3D(B, B + n, GetColor(0, 255, 0));
		DrawLine3D(C, C + n, GetColor(0, 255, 0));

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

//カメラの位置と姿勢の設定
//DxLib = > int SetCamerapositionAndTargetAndUpVec(VECTOR Position, VECTOR Target, VECTOR Up);
int SetCameraPositionAndTargetAndUpVec(
	const Vector3& cameraPosition,//カメラの位置
	const Vector3& cameraTarget, //カメラの注視点
	const Vector3& cameraUp //カメラの上の向き
)
{
	VECTOR position = { cameraPosition.x, cameraPosition.y, cameraPosition.z };
	VECTOR target = { cameraTarget.x, cameraTarget.y, cameraTarget.z };
	VECTOR up = { cameraUp.x, cameraUp.y, cameraUp.z };
	return SetCameraPositionAndTargetAndUpVec(position, target, up);
}