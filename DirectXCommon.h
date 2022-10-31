#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include <vector>
#include "WinApp.h"

// DirectX基盤
class DirectXCommon {
public:
	// namespace省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(WinApp* winApp);

private: // メンバ関数
	/// <summary>
	/// デバイス初期化
	/// </summary>
	void InitializeDevice();

	/// <summary>
	/// コマンド初期化
	/// </summary>
	void InitializeCommand();

	/// <summary>
	/// スワップチェーン初期化
	/// </summary>
	void InitializeSwapchain();

	/// <summary>
	/// レンダーターゲットビュー初期化
	/// </summary>
	void InitializeRenderTargetView();

	/// <summary>
	/// 深度バッファ初期化
	/// </summary>
	void InitializeDepthBuffer();

	/// <summary>
	/// フェンス初期化
	/// </summary>
	void InitializeFence();

private: // メンバ変数
	// DirectX12デバイス
	ComPtr<ID3D12Device> device;
	// DXGIファクトリ
	ComPtr<IDXGIFactory7> dxgiFactory;
	// スワップチェーン
	ComPtr<IDXGISwapChain4> swapChain;
	// コマンドアロケータ
	ComPtr<ID3D12CommandAllocator> commandAllocator;
	// コマンドリスト
	ComPtr<ID3D12GraphicsCommandList> commandList;
	// コマンドキュー
	ComPtr<ID3D12CommandQueue> commandQueue;
	// スワップチェーンの設定
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};
	// レンダーターゲットビューヒープ
	ComPtr<ID3D12DescriptorHeap> rtvHeap;
	// レンダーターゲットビューヒープのデスクリプタヒープ
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	// バックバッファ
	std::vector<ComPtr<ID3D12Resource>> backBuffers;
	// 深度バッファヒープ
	ComPtr<ID3D12DescriptorHeap> dsvHeap;
	// フェンス
	ComPtr<ID3D12Fence> fence;

	// WindowAPI
	WinApp* winApp_ = nullptr;
};