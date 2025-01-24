#pragma once
#include "Entity.h"
#include "GameObject.h"

class Scene : public Entity {
public:
    Scene();
    ~Scene();

    virtual void Initialize();
    virtual void Update();
    virtual void LateUpdate();
    virtual void Render(HDC hdc);

    void AddGameObject(GameObject* gameObject);

protected: // 파생 클래스에서도 접근 가능
    std::vector<GameObject*> mGameObjects;
};