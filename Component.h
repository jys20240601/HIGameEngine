#pragma once
#include "GameObject.h"

class Component {
public:
    enum class Type {
        Transform,
        SpriteRenderer,
        Other
    };

    Component(Type type);
    virtual ~Component();

    virtual void Initialize();
    virtual void Update();
    virtual void LateUpdate();
    virtual void Render(HDC hdc);

    Type GetType() const { return mType; }
    void SetOwner(GameObject* owner) { mOwner = owner; }
    GameObject* GetOwner() const { return mOwner; }

private:
    Type mType;
    GameObject* mOwner;
};