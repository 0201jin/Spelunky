#include "PlumpManClass.h"

PlumpManClass::PlumpManClass()
{
	CharacterSprite = new SpriteSheet(L"resource/C2.png", { 80, 80 }, { 270, 270 }, { 80, 80 }, { 00, 0 });

	fPlayerSpeed = 80;
	iPlayerHealth = 4;

	Location = { 270, 270 };
}
