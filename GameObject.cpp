#include "GameObject.h"
#include "Input.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	if (Input::GetKey(eKeyCode::Left))
	{
		mX -= 0.01f;
	}

	if (Input::GetKey(eKeyCode::Right))
	{
		mX += 0.01f;
	}

	if (Input::GetKey(eKeyCode::Up))
	{
		mY -= 0.01f;
	}

	if (Input::GetKey(eKeyCode::Down))
	{
		mY += 0.01f;
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