#pragma once
#include "SpriteSheet.h"
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <vector>

using namespace std;

class Stage
{
public:
	virtual void Init(ID2D1HwndRenderTarget* _D2DRenderTarget);
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

protected:
	ID2D1HwndRenderTarget* D2DRenderTarget;
};

