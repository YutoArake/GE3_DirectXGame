#pragma once
#include <windows.h>

class Input {
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(HINSTANCE hInstance, HWND hwnd);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
};