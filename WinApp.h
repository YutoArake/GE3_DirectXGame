#pragma once
#include <Windows.h>

class WinApp {
public: // �ÓI�����o�֐�
	// �E�B���h�E�v���V�[�W��
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public: // �萔
	// �E�B���h�E�T�C�Y
	static const int window_width = 1280;		// ����
	static const int window_height = 720;		// �c��

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���b�Z�[�W�̏���
	/// </summary>
	bool ProcessMessage();

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize();

private: // �����o�ϐ�
	// �E�B���h�E�N���X
	WNDCLASSEX w{};
	// �E�B���h�E�n���h��
	HWND hwnd = nullptr;

public: // �A�N�Z�b�T
	// getter
	HINSTANCE GetHInstance() const { return w.hInstance; }
	HWND GetHwnd() const { return hwnd; }
};