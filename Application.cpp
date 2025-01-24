#include "Application.h"

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
}

void Application::Run()
{
	Update();
	LateUpdate();
	Render();
}

void Application::Update()
{

}

void Application::LateUpdate()
{

}

void Application::Render()
{

}