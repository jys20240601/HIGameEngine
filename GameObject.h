#pragma once
#include "CommonInclude.h"
#include "Component.h"

class GameObject {
public:
    GameObject();
    ~GameObject();

    void SetPosition(float x, float y);
    float GetX() const { return mX; }
    float GetY() const { return mY; }

    void Initialize();
    void Update();
    void LateUpdate();
    void Render(HDC hdc);

    template <typename T>
    T* AddComponent();
    template <typename T>
    T* GetComponent();

private:
    float mX;  // X ÁÂÇ¥
    float mY;  // Y ÁÂÇ¥
    std::vector<Component*> mComponents;
};

template <typename T>
T* GameObject::AddComponent() {
    T* component = new T();
    component->SetOwner(this);
    mComponents.push_back(component);
    return component;
}

template <typename T>
T* GameObject::GetComponent() {
    for (auto comp : mComponents) {
        if (dynamic_cast<T*>(comp)) {
            return static_cast<T*>(comp);
        }
    }
    return nullptr;
}