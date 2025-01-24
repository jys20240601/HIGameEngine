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
    // GameObject ���� �� �߰�
    GameObject* obj = new GameObject();
    obj->SetPosition(300.0f, 300.0f); // �ʱ� ��ġ ����
    AddGameObject(obj);
}

void NewScene::Update() 
{
    Scene::Update();

    // P Ű�� ������ PlayScene���� ��ȯ
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