#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= 0.01f;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += 0.01f;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		mY += 0.01f;
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= 0.01f;
	}
}

void GameObject::LateUpdate()
{

};
void GameObject::Render(HDC hdc)
{
	Rectangle(hdc, 10 + mX, 10 + mY, 100 + mX, 100 + mY);
};

void GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}