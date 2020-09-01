#include "D3DApp.h"

HRESULT D3DApp::initD3D(HWND hWnd)
{
	if ((lpD3d = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return E_FAIL;
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(lpD3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&lpD3dDevice
	)))
		return E_FAIL;

	onInit();
	return S_OK;
}

void D3DApp::update()
{
	onUpdate();
}

void D3DApp::render()
{
	if (lpD3dDevice == NULL) return;
	lpD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 100), 1.0f, 0); // Clear BackBuffer

	if (SUCCEEDED(lpD3dDevice->BeginScene())) // Begin the Scene
	{
		onRender();
		lpD3dDevice->EndScene(); // End the Scene
	}

	lpD3dDevice->Present(NULL, NULL, NULL, NULL); // Page Flipping
}

void D3DApp::cleanup()
{
	onRelease();

	if (lpD3dDevice != NULL)
		lpD3dDevice->Release();

	if (lpD3d != NULL)
		lpD3d->Release();
}

D3DApp::D3DApp()
{

}

D3DApp::~D3DApp()
{

}