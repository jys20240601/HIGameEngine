#include "SceneManager.h"

// ���� ��� ���� ����
std::map<std::wstring, Scene*> SceneManager::mScene;
Scene* SceneManager::mActiveScene = nullptr;

void SceneManager::Initialize() {
    // �ʱ�ȭ �ڵ� �߰� ����
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