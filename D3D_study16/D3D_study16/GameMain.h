#pragma once
#include "D3DApp.h"
#include <d3dx9math.h>
#include <d3dx9shape.h>

class GameMain : public D3DApp
{
private:
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXVECTOR3	vecEye, vecAt, vecUp;

	LPD3DXFONT lpFont1;
	LPD3DXFONT lpFont2;

	DWORD elapsedTime;
	unsigned int fps, fpsCount;
private:
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};