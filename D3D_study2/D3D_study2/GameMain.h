#pragma once
#include "D3DApp.h"

class GameMain : public D3DApp
{
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};