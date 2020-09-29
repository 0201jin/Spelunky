#include "CharacterSelect.h"
#include "InputSystem.h"

void CharacterSelect::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	spriteSheet.push_back(new SpriteSheet(L"resource/C1.png", D2DRenderTarget, { 80, 80 }, { 270, 270 }, { 80, 80 }, { 00, 0 }));
	spriteSheet.push_back(new SpriteSheet(L"resource/C2.png", D2DRenderTarget, { 80, 80 }, { 270, 270 }, { 80, 80 }, { 00, 0 }));

	spriteSheet.push_back(new SpriteSheet(L"resource/Character_Select_BG.png", D2DRenderTarget, { 1280, 720 }, { 0, 0 }));
}

void CharacterSelect::Update(float _deltaTime)
{
	if (InputSystem::GetInst()->GetKeyPress(DIK_A))
	{
		CharacterNumber--;
		if (CharacterNumber < 0)
			CharacterNumber = spriteSheet.size() - 2;
	}

	else if (InputSystem::GetInst()->GetKeyPress(DIK_D))
	{
		CharacterNumber++;
		if (CharacterNumber >= spriteSheet.size() - 1)
			CharacterNumber = 0;
	}
}

void CharacterSelect::Render(float _deltaTime)
{
	spriteSheet[CharacterNumber]->Draw();

	spriteSheet[spriteSheet.size() - 1]->Draw();
}
