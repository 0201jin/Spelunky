#pragma once
#include "Stage.h"
#include "PlayerClass.h"
#include "MapGenerator.h"

class InGame : public Stage
{
public:
	virtual void Init(ID2D1HwndRenderTarget* _D2DRenderTarget);
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

private:
	PlayerClass* Player = nullptr;

	MapGenerator* MapGen;
};

