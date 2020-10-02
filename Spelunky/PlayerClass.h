#pragma once
#include "SpriteSheet.h"
#include <vector>

using namespace std;

class PlayerClass
{
public:
	void Update(float _deltaTime);
	void Render(float _deltaTime);

	void SetVelocity(D2D_VECTOR_2F _Velocity);
	void SetLocation(D2D_VECTOR_2F _Location) { Location = _Location; }
	D2D_VECTOR_2F GetLocation() { return Location; }

	void MoveF(int _Number);
	void MoveR(int _Number);
	void Jump(int _Number);

	void ResetAction();

protected:
	SpriteSheet* CharacterSprite;
	SpriteSheet* WeaponeSprite;

	D2D_VECTOR_2F Location;
	D2D_VECTOR_2F Velocity;

	int iPlayerHealth;

	float fPlayerSpeed;

private:
	const vector<D2D_VECTOR_2F> vMoveF = { {6, 5}, {7, 5}, {8, 5}, {9, 5}, {10, 5}, {11, 5} };
	const vector<D2D_VECTOR_2F> vMoveLR = { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0} };
	const vector<D2D_VECTOR_2F> vRope = { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {7, 7}, {8, 7}, {9, 7} };
	const vector<D2D_VECTOR_2F> vJump = { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}, {7, 9}, {8, 9}, {9, 9}, {10, 9}, {11, 9} };
};

