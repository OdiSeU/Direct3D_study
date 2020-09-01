#pragma once
#include <d3d9.h>

struct CUSTOMVERTEX
{
    FLOAT x, y, z, rhw; // The transformed position for the vertex.
    DWORD color;        // The vertex color.
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class Triangle
{
private:
    LPDIRECT3DVERTEXBUFFER9 lpVtxBuffer;
	LPDIRECT3DDEVICE9 lpD3dDevice;
public:
	void onInit(LPDIRECT3DDEVICE9 lpD3dDevice);
	void onRender();
	void onRelease();
public:
	Triangle();
	~Triangle();
};