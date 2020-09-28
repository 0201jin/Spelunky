#include "InputSystem.h"

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

bool InputSystem::Init(HINSTANCE _hInst, HWND _hWnd, int _width, int _height)
{
	screenWidth = _width;
	screenHeight = _height;

	DirectInput8Create(_hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	directInput->CreateDevice(GUID_SysKeyboard, &keyBoard, nullptr);
	keyBoard->SetDataFormat(&c_dfDIKeyboard);
	keyBoard->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	keyBoard->Acquire();
	directInput->CreateDevice(GUID_SysMouse, &mouse, nullptr);
	mouse->SetDataFormat(&c_dfDIMouse);
	mouse->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	mouse->Acquire();

	return true;
}

bool InputSystem::Frame()
{
	ProcessInput();

	return true;
}

void InputSystem::GetMouseLocation(int& _X, int& _Y)
{
	_X = mouseX;
	_Y = mouseY;
}

bool InputSystem::ReadKeyboard()
{
	keyBoard->GetDeviceState(sizeof(keyBoardState), (LPVOID)&keyBoardState);

	return true;
}

bool InputSystem::ReadMouse()
{
	mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);

	return true;
}

void InputSystem::ProcessInput()
{
	mouseX += mouseState.lX;
	mouseY += mouseState.lY;

	if (mouseX < 0)
		mouseX = 0;
	if (mouseY < 0)
		mouseY = 0;

	if (mouseX > screenWidth)
		mouseX = screenWidth;
	if (mouseY > screenHeight)
		mouseY = screenHeight;
}
