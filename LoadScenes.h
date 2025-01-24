#pragma once
#include "SceneManager.h"
//ȣ��� ��� �߰�
#include "PlayScene.h"
#include "NewScene.h"

void LoadScenes()
{
	//ȣ��� �߰�
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	SceneManager::CreateScene<NewScene>(L"NewScene");
	//SceneManager::CreateScene<PlayScene>(L"PlayScene");
	//SceneManager::CreateScene<PlayScene>(L"PlayScene");

	SceneManager::LoadScene(L"PlayScene");
}