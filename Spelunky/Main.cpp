#include "Main.h"
#include <iostream>

using namespace std;

Main::Main()
{
}

Main::~Main()
{
}

HRESULT Main::Initialize(HWND _hwnd)
{
	HRESULT hr = S_OK;

	hWnd = _hwnd;

	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &D2DFactory);

	CreateDevice();

	return hr;
}

void Main::Update(float _deltaTime)
{
	mStageMgr->GetInst()->Update(_deltaTime);
}

void Main::Render(float _deltaTime)
{
	D2DRenderTarget->BeginDraw();
	D2DRenderTarget->Clear();



	D2DRenderTarget->EndDraw();
}

HRESULT Main::CreateDevice()
{
	HRESULT hr = S_OK;

	if (!D2DRenderTarget)
	{
		RECT rc;
		GetClientRect(hWnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		hr = D2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &D2DRenderTarget);
	}

	return hr;
}
