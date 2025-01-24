#pragma once
#include "CommonInclude.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void SetPosition(float x, float y);

	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	int GetPositionX() { return mX; }
	int GetPositionY() { return mY; }

private:
	float mX;
	float mY;
};