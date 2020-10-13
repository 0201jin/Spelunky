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
		//��ġ, ������
		{{-1, -1}, {-1, -1} },
		{{0, 1}, {3, 6}},
		{{0, 0}, {1, 1}},
		{{1, 0}, {1, 1}},
		{{4, 6}, {3, 1}},
		{{7, 6}, {1, 1}}
	};
};

