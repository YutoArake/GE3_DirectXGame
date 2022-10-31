#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include "WinApp.h"

// DirectX���
class DirectXCommon {
public:
	// namespace�ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(WinApp* winApp);

private: // �����o�֐�
	/// <summary>
	/// �f�o�C�X������
	/// </summary>
	void InitializeDevice();

	/// <summary>
	/// �R�}���h������
	/// </summary>
	void InitializeCommand();

	/// <summary>
	/// �X���b�v�`�F�[��������
	/// </summary>
	void InitializeSwapchain();

	/// <summary>
	/// �����_�[�^�[�Q�b�g�r���[������
	/// </summary>
	void InitializeRenderTargetView();

	/// <summary>
	/// �[�x�o�b�t�@������
	/// </summary>
	void InitializeDepthBuffer();

	/// <summary>
	/// �t�F���X������
	/// </summary>
	void InitializeFence();

private: // �����o�ϐ�
	// DirectX12�f�o�C�X
	ComPtr<ID3D12Device> device;
	// DXGI�t�@�N�g��
	ComPtr<IDXGIFactory7> dxgiFactory;
	// �X���b�v�`�F�[��
	ComPtr<IDXGISwapChain4> swapChain;
	// �R�}���h�A���P�[�^
	ComPtr<ID3D12CommandAllocator> commandAllocator;
	// �R�}���h���X�g
	ComPtr<ID3D12GraphicsCommandList> commandList;
	// �R�}���h�L���[
	ComPtr<ID3D12CommandQueue> commandQueue;
	// �X���b�v�`�F�[���̐ݒ�
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// �����_�[�^�[�Q�b�g�r���[�q�[�v
	ComPtr<ID3D12DescriptorHeap> rtvHeap;
	// �����_�[�^�[�Q�b�g�r���[�q�[�v�̃f�X�N���v�^�q�[�v
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	// �o�b�N�o�b�t�@
	std::vector<ComPtr<ID3D12Resource>> backBuffers;
	// �[�x�o�b�t�@�q�[�v
	ComPtr<ID3D12DescriptorHeap> dsvHeap;
	// �t�F���X
	ComPtr<ID3D12Fence> fence;

	// WindowAPI
	WinApp* winApp_ = nullptr;
};