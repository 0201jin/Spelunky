#pragma once
#pragma comment(lib, "dinput8.lib") 
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	bool Init(HINSTANCE _hInst, HWND _hWnd, int _width, int _height);
	bool Frame();

	void GetMouseLocation(int& _X, int& _y);

private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* directInput = nullptr;
	IDirectInputDevice8* keyBoard = nullptr;
	IDirectInputDevice8* mouse = nullptr;

	unsigned char keyBoardState[256] = { 0, };
	DIMOUSESTATE mouseState;

	int screenWidth = 0;
	int screenHeight = 0;
	float mouseX = 0;
	float mouseY = 0;
};

