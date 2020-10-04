#include "GameMain.h"

void GameMain::onInit()
{
	RECT rect;
	D3DVIEWPORT9 vp;
	GetClientRect(hWnd, &rect);

	vp.X = 0;
	vp.Y = 0;
	vp.Width = rect.right - rect.left;
	vp.Height = rect.bottom - rect.top;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;

	vecEye.x = 5.0f;
	vecEye.y = 8.0f;
	vecEye.z = -10.0f;

	vecAt.x = 0.0f;
	vecAt.y = 0.0f;
	vecAt.z = 0.0f;

	vecUp.x = 0.0f;
	vecUp.y = 1.0f;
	vecUp.z = 0.0f;

	D3DXMatrixLookAtLH(&matView, &vecEye, &vecAt, &vecUp);
	lpD3dDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI/ 4, 1.0f, 1.0f, 100.0f);
	lpD3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
	lpD3dDevice->SetViewport(&vp);

	axis.onInit(lpD3dDevice);
	D3DXCreateTeapot(lpD3dDevice, &lpTeapotMesh, NULL);
}

void GameMain::onRender()
{
	D3DXMATRIX matRot, matTrans, matScale, matWorld;
	float scaling[3] = { 0.3f, 0.6f, 1.0f };
	D3DXVECTOR3 trans[3] = { D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2.0f, 0.0f, 0.0f), D3DXVECTOR3(5.0f, 0.0f, 0.0f) };

	axis.onRender();
	lpD3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	lpD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	D3DXMatrixRotationY(&matRot, GetTickCount() * 0.001f);

	D3DXMatrixScaling(&matScale, scaling[0], scaling[0], scaling[0]);
	D3DXMatrixTranslation(&matTrans, trans[0].x, trans[0].y, trans[0].z);
	matWorld = matScale * matRot * matTrans;
	lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	lpTeapotMesh->DrawSubset(0);

	D3DXMatrixScaling(&matScale, scaling[1], scaling[1], scaling[1]);
	D3DXMatrixTranslation(&matTrans, trans[1].x, trans[1].y, trans[1].z);
	matWorld = matScale * matRot * matTrans;
	lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	lpTeapotMesh->DrawSubset(0);

	D3DXMatrixScaling(&matScale, scaling[2], scaling[2], scaling[2]);
	D3DXMatrixTranslation(&matTrans, trans[2].x, trans[2].y, trans[2].z);
	matWorld = matScale * matTrans * matRot;
	lpD3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	lpTeapotMesh->DrawSubset(0);
}

void GameMain::onUpdate()
{
	
}

void GameMain::onRelease()
{
	lpTeapotMesh->Release();
	axis.onRelease();
}

GameMain::GameMain()
{

}


GameMain::~GameMain()
{

}