#pragma once
#pragma comment(lib, "dinput8.lib") 
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	static InputSystem* GetInst()
	{
		if (Inst == nullptr)
		{
			Inst = new InputSystem;
		}

		return Inst;
	}

	bool Init(HINSTANCE _hInst, HWND _hWnd, int _width, int _height);
	bool Frame();

	void GetMouseLocation(int& _X, int& _y);
	bool GetKeyInput(BYTE key);
	bool GetKeyPress(BYTE key);
	bool GetInputAnyKey();

private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* directInput = nullptr;
	IDirectInputDevice8* keyBoard = nullptr;
	IDirectInputDevice8* mouse = nullptr;

	BYTE keyBoardState[256] = { 0, };
	bool bCheckKeyBoardState[256] = { false, };
	DIMOUSESTATE mouseState;
	BYTE PrevKey;

	int screenWidth = 0;
	int screenHeight = 0;
	float mouseX = 0;
	float mouseY = 0;

	static InputSystem* Inst;
};

