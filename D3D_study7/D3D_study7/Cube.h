#pragma once
#include <d3dx9.h>
#include <d3dx9math.h>

class Cube
{
private:
	LPDIRECT3DDEVICE9 lpD3dDevice;
	LPDIRECT3DVERTEXBUFFER9 lpVtxBuffer;
	LPDIRECT3DINDEXBUFFER9 lpIdxBuffer;
public:
	void onIinit(LPDIRECT3DDEVICE9 lpD3dDevice);
	void onRender();
	void onRelease();
public:
	Cube();
	~Cube();
};