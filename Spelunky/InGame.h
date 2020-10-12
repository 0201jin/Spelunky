#pragma once
#include "Stage.h"
#include "PlayerClass.h"
#include "MapGenerator.h"

#include "Block.h"


class InGame : public Stage
{
public:
	virtual void Init(ID2D1HwndRenderTarget* _D2DRenderTarget);
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

private:
	PlayerClass* Player = nullptr;

	MapGenerator* MapGen;

	vector<ObjectClass*> Blocks;
	ID2D1Bitmap* vBmp[10];

	const vector<const wchar_t*> vFileName = { L"resource/dirttiles.png" };
};

