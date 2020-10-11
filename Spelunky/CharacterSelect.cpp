#include "CharacterSelect.h"
#include "InputSystem.h"
#include "StageMgr.h"

#include "GuyClass.h"
#include "PlumpManClass.h"

CharacterSelect::~CharacterSelect()
{
	delete(BGspriteSheet);

	for (int i = vPlayers.size() - 1; i > 0; i--)
		delete(vPlayers[i]);
}

void CharacterSelect::Init(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;

	vPlayers.push_back(new GuyClass());
	vPlayers.push_back(new PlumpManClass());

	BGspriteSheet = new SpriteSheet(L"resource/Character_Select_BG.png", { 1280, 720 }, { 0, 0 });
}

void CharacterSelect::Update(float _deltaTime)
{
	if (InputSystem::GetInst()->GetKeyPress(DIK_LEFTARROW) && !bCharacterSelect)
	{
		CharacterNumber--;
		if (CharacterNumber < 0)
			CharacterNumber = vPlayers.size() - 1;
	}

	else if (InputSystem::GetInst()->GetKeyPress(DIK_RIGHTARROW) && !bCharacterSelect)
	{
		CharacterNumber++;
		if (CharacterNumber >= vPlayers.size())
			CharacterNumber = 0;
	}

	else if (InputSystem::GetInst()->GetKeyPress(DIK_Z))
	{
		//캐릭터 선택
		bCharacterSelect = true;
		Player = vPlayers[CharacterNumber];
	}

	if (Player != nullptr)
	{
		Player->Update(_deltaTime);
	}
}

void CharacterSelect::Render(float _deltaTime)
{
	if (Player == nullptr)
		vPlayers[CharacterNumber]->Render(_deltaTime);

	BGspriteSheet->Draw();

	if (Player != nullptr)
	{
		fPlayTime += _deltaTime;

		if (fPlayTime <= 0.25)
		{
			Player->MoveF(fPlayTime / 0.1);

			if (fPlayTime > 0.25)
				Player->ResetAction();
		}
		else if (fPlayTime <= 0.8)
		{
			Player->SetVelocity({ 100, 0 });
			Player->MoveR((fPlayTime - 0.25) / 0.1);
		}
		else if (fPlayTime <= 1.5)
		{
			Player->ResetAction();
		}
		else if (fPlayTime <= 2.5f)
		{
			float A = (fPlayTime - 1.5f) * 100;
			Player->SetVelocity({ A * 10, (A * A - 45 * A) });
			Player->Jump((A * 0.01) / 0.1);
		}
		else
		{
			//장면 전환
			StageMgr::GetInst()->SetPlayer(Player);
			StageMgr::GetInst()->SetState(2);
		}

		Player->Render(_deltaTime);
	}
}
