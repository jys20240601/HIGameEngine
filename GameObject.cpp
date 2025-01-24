#include "GameObject.h"

GameObject::GameObject()
    : mX(0.0f), mY(0.0f) {
}

GameObject::~GameObject() {
    for (auto comp : mComponents) {
        delete comp;
    }
    mComponents.clear();
}

void GameObject::SetPosition(float x, float y) {
    mX = x;
    mY = y;
}

void GameObject::Initialize() {
    for (auto comp : mComponents) {
        comp->Initialize();
    }
}

void GameObject::Update() {
    for (auto comp : mComponents) {
        comp->Update();
    }
}

void GameObject::LateUpdate() {
    for (auto comp : mComponents) {
        comp->LateUpdate();
    }
}

void GameObject::Render(HDC hdc) {
    for (auto comp : mComponents) {
        comp->Render(hdc);
    }
}