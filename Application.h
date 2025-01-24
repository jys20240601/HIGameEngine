#pragma once

#include "CommonInclude.h"
#include "GameObject.h"

class Application
{
public:

	Application();
	~Application();

	void Initialize(HWND hWnd,UINT width,UINT height);
	void Run();

	void Update();
	void LateUpdate();
	void Render();

private:

	HWND mHwnd;
	HDC mHdc;

	HDC mBackHdc;
	HBITMAP mBackBuffer;

	UINT mWidth;
	UINT mHeight;

	GameObject mPlayer;
};