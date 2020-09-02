#pragma once
#include <d3d9.h>
#include <d3dx9math.h>

class Axis
{
private:
	LPDIRECT3DDEVICE9 lpD3dDevice;
	LPDIRECT3DVERTEXBUFFER9 lpVtxBuffer;
public:
	void onInit(LPDIRECT3DDEVICE9 lpD3dDevice);
	void onRender();
	void onRelease();
public:
	Axis();
	~Axis();
};