#pragma once
#include "Stage.h"

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

public:
	static StageMgr* GetInst()
	{
		if (Inst == nullptr)
		{
			Inst = new StageMgr;
		}

		return Inst;
	}
};

