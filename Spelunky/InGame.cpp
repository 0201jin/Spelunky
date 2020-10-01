#include "InGame.h"

void InGame::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	MapGen = new MapGenerator();
}

void InGame::Update(float _deltaTime)
{
}

void InGame::Render(float _deltaTime)
{
}
