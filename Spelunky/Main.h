#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

#include "StageMgr.h"

class Main
{
public:
	Main();
	~Main();

	HRESULT Initialize(HWND _hwnd);

	void Update(float _deltaTime);
	void Render(float _deltaTime);

private:
	HRESULT CreateDevice();
	StageMgr* mStageMgr;

private:
	HWND hWnd;
	ID2D1Factory* D2DFactory;
	ID2D1HwndRenderTarget* D2DRenderTarget;
};

