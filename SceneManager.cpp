#include "SceneManager.h"

// 정적 멤버 변수 정의
std::map<std::wstring, Scene*> SceneManager::mScene;
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize() {
    // 초기화 코드 추가 가능
}

void SceneManager::Update() {
    if (mActiveScene) {
        mActiveScene->Update();
    }
}

void SceneManager::LateUpdate() {
    if (mActiveScene) {
        mActiveScene->LateUpdate();
    }
}

void SceneManager::Render(HDC hdc) {
    if (mActiveScene) {
        mActiveScene->Render(hdc);
    }
}