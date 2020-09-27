#pragma once
#include "Stage.h"

class StageMgr
{
public:
	StageMgr();
	~StageMgr();

	void SetState(int _id);

	void Update(float _deltaTime);
	void Render(float _deltaTime);

private:
	static StageMgr* Inst;

	Stage* mStage;

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

