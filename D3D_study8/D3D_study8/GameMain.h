#pragma once
#include "D3DApp.h"
#include "Axis.h"
#include "Cube.h"
#include <d3dx9math.h>

class GameMain : public D3DApp
{
private:
	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXVECTOR3	vecEye, vecAt, vecUp;
	Axis axis;
	Cube cube;
	LPD3DXMESH lpBoxMesh;
	LPD3DXMESH lpSphereMesh;
	LPD3DXMESH lpTeapotMesh;
	LPD3DXMESH lpCylinderMesh;
private:
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};