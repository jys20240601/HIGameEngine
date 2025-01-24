#include "Application.h"
#include "Input.h"
#include "TimeManager.h"

Application::Application()
	:mHwnd(nullptr)
	,mHdc(nullptr)
	,mBackHdc(nullptr)
	,mBackBuffer(nullptr)
	,mWidth(0)
	,mHeight(0)
{

}

Application::~Application()
{
	ReleaseDC(mHwnd, mHdc);
}


void Application::Initialize(HWND hWnd, UINT width, UINT height)
{
	mHwnd = hWnd;
	mHdc = GetDC(hWnd);

	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	mWidth = rect.right - rect.left;
	mHeight = rect.bottom - rect.top;

	SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
	ShowWindow(mHwnd, true);

	mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

	mBackHdc = CreateCompatibleDC(mHdc);

	HBITMAP oldbitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
	DeleteObject(oldbitmap);

	Input::Initialize();
	TimeManager::Initialize();
}

void Application::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Application::Update()
{
	Input::Update();
	TimeManager::Update();

	mPlayer.Update();
}

void Application::LateUpdate()
{

}

void Application::Render()
{
	Rectangle(mBackHdc, 0, 0, 1600, 900);

	mPlayer.Render(mBackHdc);

	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
}