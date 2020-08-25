#pragma once
#include <Windows.h>
#include <d3d9.h>

HWND g_hWnd;

LPDIRECT3D9 g_d3d = NULL;
LPDIRECT3DDEVICE9 g_d3dDevice = NULL;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
HRESULT initD3D(HWND hWnd);
void render();
void cleanup();