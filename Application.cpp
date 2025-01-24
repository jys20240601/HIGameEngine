#include "Application.h"
#include "Input.h"
#include "TimeManager.h"
#include "SceneManager.h"

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

	//더블 버퍼링
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
	SceneManager::Initialize();

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
	SceneManager::Update();
}

void Application::LateUpdate()
{

}

void Application::Render()
{
	//Double Buffering
	Rectangle(mBackHdc, -1, -1, 1601, 901);

	SceneManager::Render(mBackHdc);

	//Double Buffering
	BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);

}