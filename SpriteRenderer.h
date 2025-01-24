#pragma once
#include "Component.h"
#include "CommonInclude.h"

class SpriteRenderer : public Component {
public:
    SpriteRenderer();
    ~SpriteRenderer();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void LateUpdate() override;
    virtual void Render(HDC hdc) override;

    void ImageLoad(const std::wstring& path);

private:
    Gdiplus::Image* mImage;
    UINT mWidth;
    UINT mHeight;
};