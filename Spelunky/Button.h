#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include "UMGObj.h"

class Button : public UMGObj
{
public:
	Button();
	~Button();

	void Initailize(float _x, float _y, float _width, float _height, ID2D1HwndRenderTarget* _D2DRenderTarget);

	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

private:
	IWICImagingFactory* wicFactory;
	IWICBitmapDecoder* Decoder;
};

