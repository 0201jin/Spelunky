#pragma once
#include "Stage.h"
#include "PlayerClass.h"

class CharacterSelect : public Stage
{
public:
	~CharacterSelect();
	virtual void Init(ID2D1HwndRenderTarget* _D2DRenderTarget);
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

private:
	SpriteSheet* BGspriteSheet;
	vector<PlayerClass*> vPlayers;
	PlayerClass* Player = nullptr;

	bool bCharacterSelect = false;
	float fPlayTime = 0;

	int CharacterNumber = 0;
};

