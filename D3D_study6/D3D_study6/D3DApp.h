#pragma once
#include <d3d9.h>

class D3DApp
{
protected:
	LPDIRECT3D9 lpD3d = NULL;
	LPDIRECT3DDEVICE9 lpD3dDevice = NULL;
	HWND hWnd;

protected:
	virtual void onInit() = 0;
	virtual void onUpdate() = 0;
	virtual void onRender() = 0;
	virtual void onRelease() = 0;

public:
	HRESULT initD3D(HWND hWnd);
	void update();
	void render();
	void cleanup();

public:
	D3DApp();
	~D3DApp();
};