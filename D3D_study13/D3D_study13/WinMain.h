#pragma once
#include <Windows.h>
#include "GameMain.h"

HWND g_hWnd;
GameMain g_GameMain;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);