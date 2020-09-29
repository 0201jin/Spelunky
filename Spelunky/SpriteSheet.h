#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <iostream>

class SpriteSheet
{
public:
	SpriteSheet(const wchar_t* _fileName, ID2D1HwndRenderTarget* _renderTarget, 
		D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Locatioon, 
		D2D_VECTOR_2F _ImageSize = {-1, -1}, D2D_VECTOR_2F _ImageLocation = { 0, 0 });
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

	float fImageWidth = 0;
	float fImageHeight = 0;
	float fImageX = 0;
	float fImageY = 0;
};

