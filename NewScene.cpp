#include "NewScene.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Input.h"

NewScene::NewScene() 
{

}
NewScene::~NewScene() 
{

}

void NewScene::Initialize() 
{
    // GameObject 생성 및 추가
    GameObject* obj = new GameObject();
    obj->SetPosition(300.0f, 300.0f); // 초기 위치 설정
    AddGameObject(obj);
}

void NewScene::Update() 
{
    Scene::Update();

    // P 키를 누르면 PlayScene으로 전환
    if (Input::GetKeyDown(eKeyCode::P)) 
    {
        SceneManager::LoadScene(L"PlayScene");
    }
}

void NewScene::LateUpdate() 
{
    Scene::LateUpdate();
}

void NewScene::Render(HDC hdc) 
{
    Scene::Render(hdc);
}