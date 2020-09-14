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
	D3DXMATRIX matRotation;

	axis.onRender();
	lpD3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	lpD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	D3DXMatrixRotationX(&matRotation, GetTickCount() * 0.004f);
	//D3DXMatrixRotationY(&matRotation, GetTickCount() * 0.004f);
	//D3DXMatrixRotationZ(&matRotation, GetTickCount() * 0.004f);
	lpD3dDevice->SetTransform(D3DTS_WORLD, &matRotation);
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