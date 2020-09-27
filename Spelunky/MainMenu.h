#pragma once
#include "Stage.h"

class MainMenu : public Stage
{
public:
	virtual void Init();
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);
};

