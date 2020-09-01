#pragma once
#include "D3DApp.h"
#include "Triangle.h"

class GameMain : public D3DApp
{
private:
	Triangle triangle;
private:
	virtual void onInit();
	virtual void onRender();
	virtual void onUpdate();
	virtual void onRelease();
public:
	GameMain();
	~GameMain();
};