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

	D3DXCreateFont(lpD3dDevice, 20, 0 FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "System", &lpFont1);
	D3DXCreateFont(lpD3dDevice, 20, 0 FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "돋움체", &lpFont2);

}

void GameMain::onRender()
{
	char string[100];
	RECT rt;

	SetRect(&rt, 100, 100, 0, 0);
	lpFont1->DrawText(NULL, "3D 게임 프로그래밍", -1, &rt, D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f));
}

void GameMain::onUpdate()
{
	
}

void GameMain::onRelease()
{
	
}

GameMain::GameMain()
{

}


GameMain::~GameMain()
{

}