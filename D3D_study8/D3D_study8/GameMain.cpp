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
	//cube.onIinit(lpD3dDevice);
	//D3DXCreateBox(lpD3dDevice, 2.0f, 2.0f, 2.0f, &lpBoxMesh, NULL);
	//D3DXCreateSphere(lpD3dDevice, 3.0f, 30, 10, &lpSphereMesh, NULL);
	//D3DXCreateTeapot(lpD3dDevice, &lpTeapotMesh, NULL);
	D3DXCreateCylinder(lpD3dDevice, 2.0f, 2.0f, 5.0f, 30, 10, &lpCylinderMesh, NULL);
}

void GameMain::onRender()
{
	axis.onRender();
	//cube.onRender();
	lpD3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	lpD3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	//lpBoxMesh->DrawSubset(0);
	//lpSphereMesh->DrawSubset(0);
	//lpTeapotMesh->DrawSubset(0);
	lpCylinderMesh->DrawSubset(0);
	
}

void GameMain::onUpdate()
{
	
}

void GameMain::onRelease()
{
	axis.onRelease();
	//cube.onRelease();
	//lpBoxMesh->Release();
	//lpSphereMesh->Release();
	//lpTeapotMesh->Release();
	lpCylinderMesh->Release();

}

GameMain::GameMain()
{

}


GameMain::~GameMain()
{

}