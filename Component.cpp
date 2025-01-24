#include "Component.h"

Component::Component(Type type)
    : mType(type), mOwner(nullptr) {
}

Component::~Component() {
}

void Component::Initialize() {
}

void Component::Update() {
}

void Component::LateUpdate() {
}

void Component::Render(HDC hdc) {
}