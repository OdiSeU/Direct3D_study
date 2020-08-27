#pragma once
#include "D3DApp.h"

struct CUSTOMVERTEX
{
	float x, y, z, rhw;
	DWORD color;  // ARGB
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class GameMain : public D3DApp
{
private:
	LPDIRECT3DVERTEXBUFFER9 lpVtxBuffer;
private:
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};