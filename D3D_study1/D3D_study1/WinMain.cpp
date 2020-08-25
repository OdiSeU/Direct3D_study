#include "WinMain.h"

HRESULT initD3D(HWND hWnd)
{
	if ((g_d3d = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
		return E_FAIL;
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	if (FAILED(g_d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, 
		&g_d3dDevice
	)))
		return E_FAIL;
	return S_OK;
}

void cleanup()
{
	if (g_d3dDevice != NULL)
		g_d3dDevice->Release();

	if (g_d3d != NULL)
		g_d3d->Release();
}

void render()
{
	if (g_d3dDevice == NULL) return;
	g_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0); // Clear BackBuffer

	if (SUCCEEDED(g_d3dDevice->BeginScene())) // Begin the Scene
	{
		//Rendering here
		g_d3dDevice->EndScene(); // End the Scene
	}

	g_d3dDevice->Present(NULL, NULL, NULL, NULL); // Page Flipping
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDC_ICON);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MyApp");

	RegisterClass(&wc);					// Regist window class

	g_hWnd = hWnd = CreateWindowW(
		TEXT("MyApp"),						// lpClassName
		TEXT("Sample Application"),		// lpWindowName
		WS_OVERLAPPEDWINDOW,		// dwStyle
		100, 100,								//	X	,	Y	
		300, 300,								// Width, Height
		NULL,									// hWndParent
		NULL,									// hMenu
		hInstance,								// hInstance
		NULL										// lpParam
	);

	ShowWindow(hWnd, SW_SHOW);	 // Print window on screen

	initD3D(g_hWnd);

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	 // Message loop
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			render();
		}
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_PAINT:
		render();
		break;
	case WM_DESTROY:
		cleanup();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
		break;
	}

	return 0;
}