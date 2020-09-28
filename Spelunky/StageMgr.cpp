#include "StageMgr.h"

#include "MainMenu.h"

StageMgr* StageMgr::Inst = nullptr;

StageMgr::StageMgr()
{
	mStage = new MainMenu();
}

StageMgr::~StageMgr()
{
}

void StageMgr::SetState(int _id)
{
}

void StageMgr::SetRenderTarget(ID2D1HwndRenderTarget* _D2DRenderTarget)
{
	D2DRenderTarget = _D2DRenderTarget;
	mStage->Init(D2DRenderTarget);
}

void StageMgr::Update(float _deltaTime)
{
	mStage->Update(_deltaTime);
}

void StageMgr::Render(float _deltaTime)
{
	mStage->Render(_deltaTime);
}
