#include "GameObject.h"
#include "Input.h"
#include "TimeManager.h"

GameObject::GameObject()
    : mX(0.0f), mY(0.0f)
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
    // 키 입력 처리
    if (Input::GetKey(eKeyCode::Left))
    {
        mX -= 100.0f * TimeManager::DeltaTime();
    }

    if (Input::GetKey(eKeyCode::Right))
    {
        mX += 100.0f * TimeManager::DeltaTime();
    }

    if (Input::GetKey(eKeyCode::Up))
    {
        mY -= 100.0f * TimeManager::DeltaTime();
    }

    if (Input::GetKey(eKeyCode::Down))
    {
        mY += 100.0f * TimeManager::DeltaTime();
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