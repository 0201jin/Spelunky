#pragma once
#include "Stage.h"

class MainMenu : public Stage
{
public:
	virtual void Init(ID2D1HwndRenderTarget* _D2DRenderTarget);
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

	~MainMenu();

private:
	vector<SpriteSheet*> spriteSheet;
};

