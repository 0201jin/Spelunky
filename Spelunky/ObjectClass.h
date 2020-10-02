#pragma once
#include "SpriteSheet.h"
#include <vector>

using namespace std;

class ObjectClass
{
public:
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);
	virtual void SetLocation(int _x, int _y);
	virtual void SetObjectNumber(int _number);

protected:
	SpriteSheet* Sprite;
};

