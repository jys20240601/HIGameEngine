#include "Application.h"
#include "Input.h"

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
	mPlayer.Update();
}

void Application::LateUpdate()
{

}

void Application::Render()
{
	mPlayer.Render(mHdc);
}