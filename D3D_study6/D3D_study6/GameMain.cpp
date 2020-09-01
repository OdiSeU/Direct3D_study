#include "GameMain.h"

void GameMain::onInit()
{
	triangle.onInit(lpD3dDevice);
}

void GameMain::onRender()
{
	triangle.onRender();
}

void GameMain::onUpdate()
{
	
}

void GameMain::onRelease()
{
	triangle.onRelease();
}

GameMain::GameMain()
{

}


GameMain::~GameMain()
{

}