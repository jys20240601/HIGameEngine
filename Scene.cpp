#include "Scene.h"

Scene::Scene() {
}

Scene::~Scene() {
    // GameObject 메모리 해제
    for (GameObject* gameObj : mGameObjects) {
        delete gameObj;
    }
}

void Scene::Initialize() {
}

void Scene::Update() {
    for (GameObject* gameObj : mGameObjects) {
        gameObj->Update();
    }
}

void Scene::LateUpdate() {
    for (GameObject* gameObj : mGameObjects) {
        gameObj->LateUpdate();
    }
}

void Scene::Render(HDC hdc) {
    for (GameObject* gameObj : mGameObjects) {
        gameObj->Render(hdc);
    }
}

void Scene::AddGameObject(GameObject* gameObject) {
    mGameObjects.push_back(gameObject);
}