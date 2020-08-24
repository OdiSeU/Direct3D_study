#include "WinMain.h"

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
		TEXT("MyApp"),					// lpClassName
		TEXT("Sample Application"),		// lpWindowName
		WS_OVERLAPPEDWINDOW,			// dwStyle
		CW_USEDEFAULT, CW_USEDEFAULT,	//	X	,	Y	
		CW_USEDEFAULT, CW_USEDEFAULT,	// Width, Height
		NULL,							// hWndParent
		NULL,							// hMenu
		hInstance,						// hInstance
		NULL							// lpParam
	);

	ShowWindow(hWnd, SW_SHOW);			// Print window on screen

	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//Message loop
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, iMsg, wParam, lParam);
		break;
	}

	return 0;
}