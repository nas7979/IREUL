#include "DXUT.h"
#include "cSceneManager.h"


cSceneManager::cSceneManager()
{
}


cSceneManager::~cSceneManager()
{
}

void cSceneManager::Init()
{
}

void cSceneManager::Update()
{
	if (m_New)
	{
		if (m_Cur)
			m_Cur->Release();
		m_Cur = m_New;
		m_New = nullptr;
		m_Cur->Init();
		SYSTEM->CreateButton();
	}
	if (m_Cur)
	{
		m_Cur->Update();
	}
}

void cSceneManager::Render1()
{
	if (m_Cur)
	{
		m_Cur->Render1();
	}
}

void cSceneManager::Render2()
{
	if (m_Cur)
	{
		m_Cur->Render2();
	}
}

void cSceneManager::RenderGlobal()
{
	if (m_Cur)
	{
		m_Cur->RenderGlobal();
	}
}

void cSceneManager::Release()
{
	for (auto& iter : m_Scenes)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
}

void cSceneManager::AddScene(string _Key, cScene * _Scene)
{
	m_Scenes.insert(make_pair(_Key, _Scene));
}

void cSceneManager::ChangeScene(string _Key)
{
	m_New = m_Scenes[_Key];
}

cStage* cSceneManager::GetStage()
{
	return static_cast<cStage*>(m_Cur);
}

string cSceneManager::GetCurSceneKey()
{
	for (auto& iter : m_Scenes)
	{
		if (iter.second == m_Cur)
		{
			return iter.first;
		}
	}
}
