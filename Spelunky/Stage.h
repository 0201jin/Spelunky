#pragma once

class Stage
{
public:
	virtual void Init();
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);
};

