#include "SpriteRenderer.h"
#include "GameObject.h"

SpriteRenderer::SpriteRenderer()
    : Component(Type::SpriteRenderer), mImage(nullptr), mWidth(0), mHeight(0) {
}

SpriteRenderer::~SpriteRenderer() {
    if (mImage) {
        delete mImage;
        mImage = nullptr;
    }
}

void SpriteRenderer::Initialize() {
}

void SpriteRenderer::Update() {
}

void SpriteRenderer::LateUpdate() {
}

void SpriteRenderer::Render(HDC hdc) {
    // GameObject의 위치 데이터를 직접 가져옵니다.
    float x = GetOwner()->GetX();
    float y = GetOwner()->GetY();

    Gdiplus::Graphics graphics(hdc);
    graphics.DrawImage(mImage, Gdiplus::Rect(x, y, mWidth, mHeight));
}

void SpriteRenderer::ImageLoad(const std::wstring& path) {
    if (mImage) {
        delete mImage;
        mImage = nullptr;
    }

    mImage = Gdiplus::Image::FromFile(path.c_str());
    if (mImage) {
        mWidth = mImage->GetWidth();
        mHeight = mImage->GetHeight();
    }
}