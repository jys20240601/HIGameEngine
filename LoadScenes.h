#pragma once
#include "SceneManager.h"
//호출씬 헤더 추가
#include "PlayScene.h"
#include "NewScene.h"

void LoadScenes()
{
	//호출씬 추가
	SceneManager::CreateScene<PlayScene>(L"PlayScene");
	SceneManager::CreateScene<NewScene>(L"NewScene");
	//SceneManager::CreateScene<PlayScene>(L"PlayScene");
	//SceneManager::CreateScene<PlayScene>(L"PlayScene");

	SceneManager::LoadScene(L"PlayScene");
}