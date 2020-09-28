#include "MainMenu.h"
#include <iostream>

void MainMenu::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	spriteSheet.push_back(new SpriteSheet(L"resource/Thumbnail.jpg", D2DRenderTarget, { 1280, 720 }, { 0, 0 }));
	spriteSheet.push_back(new SpriteSheet(L"resource/PressAnyKey.png", D2DRenderTarget, { 640, 128 }, { 320, 580 }));
}

void MainMenu::Update(float _deltaTime)
{
}

void MainMenu::Render(float _deltaTime)
{
	spriteSheet[0]->Draw();
	spriteSheet[1]->Draw(_deltaTime);
	//for (int i = 0; i < spriteSheet.size(); i++)
	//	spriteSheet[i]->Draw();
}
