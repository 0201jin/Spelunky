#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <iostream>

class SpriteSheet
{
public:
	SpriteSheet(const wchar_t* _fileName, ID2D1HwndRenderTarget* _renderTarget, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Locatioon);
	~SpriteSheet();

	void Draw();
	void Draw(float _deltaTime);

private:
	ID2D1Bitmap* bmp;
	ID2D1HwndRenderTarget* D2DRenderTarget;

	D2D_VECTOR_2F Size;
	D2D_VECTOR_2F Location;

	float fOpacity = 1;
	float fTime = 0;
};

