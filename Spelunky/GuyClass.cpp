#include "GuyClass.h"

GuyClass::GuyClass()
{
	CharacterSprite = new SpriteSheet(L"resource/C1.png", { 80, 80 }, { 270, 270 }, { 80, 80 }, { 00, 0 });

	fPlayerSpeed = 200;
	iPlayerHealth = 3;

	Location = { 270, 270 };
}
