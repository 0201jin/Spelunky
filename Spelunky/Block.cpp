#include "Block.h"

#define IMAGE_SIZE 80

Block::Block()
{
	Sprite = new SpriteSheet(L"resource/dirttiles.png", { IMAGE_SIZE, IMAGE_SIZE }, { 0, 0 }, { 64, 64 }, { 0, 0 });
}

void Block::SetObjectNumber(int _number)
{
	int x = (rand() % (SpriteNumber[_number][1].X)) + SpriteNumber[_number][0].X;
	int y = (rand() % (SpriteNumber[_number][1].Y)) + SpriteNumber[_number][0].Y;

	Sprite->SetImageLocation({ (float)x, (float)y });
}

void Block::SetLocation(int _x, int _y)
{
	Sprite->SetLocation({ (float)_x * IMAGE_SIZE, (float)_y * IMAGE_SIZE });
}

void Block::Render(float _deltaTime)
{
	Sprite->Draw();
}
