#pragma once
#include "cScene.h"
#include "cStage.h"
//씬들을 생성, 관리, 변경하는 매니저이다. 스테이지 씬이 필요할 때를 위해 cStage*의 형태로 static_cast하여 반환하는 함수를 만들어 두았으며,
//현재 씬이 어느 씬인지 string의 형식으로 반환하는 함수 또한 만들어 두었다.
class cSceneManager : public cSingleton<cSceneManager>
{
public:
	cSceneManager();
	~cSceneManager();

	void Init();
	void Update();
	void Render1();
	void Render2();
	void RenderGlobal();
	void Release();

private:
	cScene* m_Cur = nullptr;
	cScene* m_New = nullptr;

	map<string, cScene*> m_Scenes;

public:
	void AddScene(string _Key, cScene* _Scene);
	void ChangeScene(string _Key);
	cStage* GetStage();
	string GetCurSceneKey();
};

#define SCENE cSceneManager::GetInstance()