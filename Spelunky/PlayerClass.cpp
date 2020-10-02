#include "PlayerClass.h"
#include "InputSystem.h"

void PlayerClass::Update(float _deltaTime)
{
	if (InputSystem::GetInst()->GetKeyInput(DIK_LEFTARROW))
	{
		Velocity.x = -fPlayerSpeed;
	}
	else if (InputSystem::GetInst()->GetKeyInput(DIK_RIGHTARROW))
	{
		Velocity.x = fPlayerSpeed;
	}

	Location.x += Velocity.x * _deltaTime;
	Location.y += Velocity.y * _deltaTime;
	Velocity = { 0, 0 };

	CharacterSprite->SetLocation(Location);
}

void PlayerClass::Render(float _deltaTime)
{
	CharacterSprite->Draw();
}

void PlayerClass::SetVelocity(D2D_VECTOR_2F _Velocity)
{
	Velocity.x = _Velocity.x;
	Velocity.y = _Velocity.y;
}

void PlayerClass::MoveF(int _Number)
{
	_Number %= vMoveF.size();
	CharacterSprite->SetImageLocation(vMoveF[_Number]);

	Velocity.y += 100.0f;
}

void PlayerClass::MoveR(int _Number)
{
	_Number %= vMoveLR.size();
	CharacterSprite->SetImageLocation(vMoveLR[_Number]);
}

void PlayerClass::Jump(int _Number)
{
	if (_Number >= vJump.size() - 1)
		_Number = vJump.size() - 1;
	else
		_Number %= vJump.size();

	CharacterSprite->SetImageLocation(vJump[_Number]);
}

void PlayerClass::ResetAction()
{
	CharacterSprite->SetImageLocation(vMoveLR[0]);
}
