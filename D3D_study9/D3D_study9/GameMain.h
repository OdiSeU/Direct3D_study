#pragma once
#include "D3DApp.h"
#include "Axis.h"
#include <d3dx9math.h>

class GameMain : public D3DApp
{
private:
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXVECTOR3	vecEye, vecAt, vecUp;
	Axis axis;
	LPD3DXMESH lpTeapotMesh;
	float scale;
private:
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};