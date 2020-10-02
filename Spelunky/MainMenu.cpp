#include "MainMenu.h"
#include <iostream>
#include "InputSystem.h"
#include "StageMgr.h"

void MainMenu::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	new SpriteSheet(D2DRenderTarget);
	spriteSheet.push_back(new SpriteSheet(L"resource/Thumbnail.jpg", { 1280, 720 }, { 0, 0 }));
	spriteSheet.push_back(new SpriteSheet(L"resource/PressAnyKey.png", { 640, 128 }, { 320, 580 }));
}

void MainMenu::Update(float _deltaTime)
{
	if (InputSystem::GetInst()->GetInputAnyKey())
		StageMgr::GetInst()->SetState(1);
}

void MainMenu::Render(float _deltaTime)
{
	spriteSheet[0]->Draw();
	spriteSheet[1]->Draw(_deltaTime);
	//for (int i = 0; i < spriteSheet.size(); i++)
	//	spriteSheet[i]->Draw();
}

MainMenu::~MainMenu()
{
	delete(spriteSheet[0]);
	delete(spriteSheet[1]);
}
