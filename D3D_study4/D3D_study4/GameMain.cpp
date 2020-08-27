#include "GameMain.h"

void GameMain::onInit()
{
	CUSTOMVERTEX vertices[] =
	{
		{ 150.0f,  50.0f, 0.5f, 1.0f, 0xffff0000, },
		{ 250.0f, 250.0f, 0.5f, 1.0f, 0xff00ff00, },
		{  50.0f, 250.0f, 0.5f, 1.0f, 0xff00ffff, },
	};

	d3dDevice->CreateVertexBuffer(
		3 * sizeof(CUSTOMVERTEX),
		0,
		D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT,
		&lp_vtxBuffer,
		NULL
	);
}

void GameMain::onRender()
{

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