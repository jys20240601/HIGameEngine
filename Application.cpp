#include "Application.h"
#include "Input.h"
#include "TimeManager.h"

Application::Application()
	:mHwnd(nullptr)
	, mHdc(nullptr)
{

}

Application::~Application()
{
	ReleaseDC(mHwnd, mHdc);
}


void Application::Initialize(HWND hWnd)
{
	mHwnd = hWnd;
	mHdc = GetDC(hWnd);

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
	mPlayer.Render(mHdc);
}