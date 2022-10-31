#pragma once
#include <Windows.h>

class WinApp {
public: // 静的メンバ関数
	// ウィンドウプロシージャ
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public: // 定数
	// ウィンドウサイズ
	static const int window_width = 1280;		// 横幅
	static const int window_height = 720;		// 縦幅

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// メッセージの処理
	/// </summary>
	bool ProcessMessage();

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

private: // メンバ変数
	// ウィンドウクラス
	WNDCLASSEX w{};
	// ウィンドウハンドル
	HWND hwnd = nullptr;

public: // アクセッサ
	// getter
	HINSTANCE GetHInstance() const { return w.hInstance; }
	HWND GetHwnd() const { return hwnd; }
};