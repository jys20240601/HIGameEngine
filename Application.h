#pragma once

#include "CommonInclude.h"

class Application
{
public:

	Application();
	~Application();

	void Initialize(HWND hWnd);
	void Run();

	void Update();
	void LateUpdate();
	void Render();

private:

	HWND mHwnd;
	HDC mHdc;

};