#include "Button.h"

Button::Button()
{
}

Button::~Button()
{
}

void Button::Initailize(float _x, float _y, float _width, float _height, ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&wicFactory));
}

void Button::Update(float _deltaTime)
{
}

void Button::Render(float _deltaTime)
{
}
