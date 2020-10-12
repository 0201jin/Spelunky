#pragma once
#include "ObjectClass.h"

typedef struct IPosition
{
	int X;
	int Y;
}IPosition;

class Block : public ObjectClass
{
public:
	Block(ID2D1Bitmap* _bmp);

	virtual void SetObjectNumber(int _number);
	virtual void SetLocation(int _x, int _y);
	virtual void Render(float _deltaTime);

private:
	vector<vector<IPosition>> SpriteNumber =
	{
		{{-1, -1}, {-1, -1} },
		{{0, 1}, {3, 6}}
	};
};

