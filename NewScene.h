#pragma once
#include "Scene.h"

class NewScene : public Scene {
public:
    NewScene();
    ~NewScene();

    void Initialize() override;
    void Update() override;
    void LateUpdate() override;
    void Render(HDC hdc) override;
};