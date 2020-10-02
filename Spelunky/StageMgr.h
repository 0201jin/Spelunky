#pragma once
#include "Stage.h"
#include "PlayerClass.h"

class StageMgr
{
public:
	StageMgr();
	~StageMgr();

	void SetState(int _id);
	void SetRenderTarget(ID2D1HwndRenderTarget* _D2DRenderTarget);

	void Update(float _deltaTime);
	void Render(float _deltaTime);

private:
	static StageMgr* Inst;

	Stage* mStage;
	ID2D1HwndRenderTarget* D2DRenderTarget;
	PlayerClass* mPlayer;

public:
	PlayerClass* GetPlayer()
	{
		return mPlayer;
	}

	void SetPlayer(PlayerClass* _player)
	{
		mPlayer = _player;
	}

	static StageMgr* GetInst()
	{
		if (Inst == nullptr)
		{
			Inst = new StageMgr;
		}

		return Inst;
	}
};

