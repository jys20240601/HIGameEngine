#include "PlayScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "SpriteRenderer.h"

PlayScene::PlayScene() 
{

}

PlayScene::~PlayScene() 
{
    for (GameObject* obj : mGameObjects) 
    {
        delete obj;
    }
}

void PlayScene::Initialize() 
{
    GameObject* bg = new GameObject();

    // GameObject의 위치 설정
    bg->SetPosition(0, 0);

    // SpriteRenderer 추가
    SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
    sr->ImageLoad(L"Resources/CloudOcean.png");

    AddGameObject(bg);
}

void PlayScene::Update() 
{
    Scene::Update();

    if (Input::GetKeyDown(eKeyCode::N))
    {
        SceneManager::LoadScene(L"NewScene");
    }
}

void PlayScene::LateUpdate() 
{
    Scene::LateUpdate();
}

void PlayScene::Render(HDC hdc) 
{
    Scene::Render(hdc);
}