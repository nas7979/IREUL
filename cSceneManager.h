#pragma once
#include "cScene.h"
#include "cStage.h"
//������ ����, ����, �����ϴ� �Ŵ����̴�. �������� ���� �ʿ��� ���� ���� cStage*�� ���·� static_cast�Ͽ� ��ȯ�ϴ� �Լ��� ����� �ξ�����,
//���� ���� ��� ������ string�� �������� ��ȯ�ϴ� �Լ� ���� ����� �ξ���.
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